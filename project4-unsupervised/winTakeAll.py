#!/usr/local/bin/python3
import sys
import numpy as np
from random import *
import readPPM as rpp

def euc(A, B, n = 3):
		dist = 0
		for i in range(n):
				dist += (A[i] - B[i]) ** 2
		return dist ** (1/2)

def winnerTakeAll(ppm, k, eps, dist = euc):
		means = np.random.uniform(0, 255, k*3).reshape([k,3])

		w, h = len(ppm[0]), len(ppm)
		#h*w matrix with each element being [cluster, distance]
		mappings = np.zeros((h,w, 2), dtype=np.float)
		mappings.fill(float("1000000000000000000"))

		iteration = 0
		changed = True
		while changed and iteration < 30:
				iteration += 1
				print("Starting iteration:", iteration, file=sys.stderr)
				changed = False
				#map all the pixels to a clusters and if any single one changes then changed = True
				for i in range(h):
						for j in range(w): #each pixel
								winner = int(mappings[i,j,0])
								bestDist = mappings[i,j,1]
								for t in range(k): #each cluster
										#compute the distance
										newDist = dist(ppm[i,j], means[t])
										#if strictly less than
										if newDist < bestDist:
												#a class changed
												changed = True
												bestDist = newDist
												winner = t
								if winner != int(mappings[i,j,0]):
										means[winner] = means[winner] + eps * (ppm[i,j] - means[winner])
										mappings[i,j,0] = winner
										mappings[i,j,1] = bestDist
		return mappings, means	

def main():
		ppm, mI = rpp.readImage()
		mappings, clusters = winnerTakeAll(ppm, int(sys.argv[2]), 0.1)
		rpp.writeImage(mappings, mI, clusters)
		return 0

if __name__ == "__main__":
		sys.exit(main())
