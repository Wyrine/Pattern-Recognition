#!/usr/local/bin/python3

import sys
import sklearn.cluster as sklc
import readPPM as rpp

ppm, mI = rpp.readImage()
w, h = len(ppm[0]), len(ppm)
p2 = ppm.reshape([h*w, 3])
a, b = sklc.mean_shift(p2, bandwidth=None if len(sys.argv) <= 2 else float(sys.argv[2]), n_jobs = -1)

print("P3")
print(w,h)
print(mI)
for i in b:
		for var in a[i]:
				print(int(var), end=" ")
		print()


