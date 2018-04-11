#!/usr/local/bin/python3
import sys
import numpy as np

def readImage():
		with open(sys.argv[1]) as f:
				#get the header
				f.readline()
				#get comments
				tmp = f.readline()
				while tmp[0] == '#':
						tmp = f.readline()
				#get width and height
				tmp = tmp.replace('\n', '').split(' ')
				w, h = int(tmp[0]), int(tmp[1])
				ppm = np.zeros((h,w,3), dtype=np.int)
				mI = int(f.readline().replace('\n', '').replace(' ', ''))
				data = f.read().replace('\n', ' ').split()
				k = 0
				for i in range(h):
						for j in range(w):
								ppm[i,j] = [data[k], data[k+1], data[k+2]]
								k+=3
		return ppm, mI

def writeImage(mappings, mI, clusters):
		print("P3")
		print(len(mappings), len(mappings[0]))
		print(mI)
		for i in range(len(mappings)):
				for j in range(len(mappings[0])):
						for k in range(3):
								print(int(clusters[int(mappings[i,j,0]), k]), end=" ")
						print()
