#!/usr/local/bin/python3

import matplotlib.pyplot as plt
from sys import argv
import numpy as np
from operator import itemgetter


def avgEucError(A,B):
		err = np.zeros(3, dtype=np.float64)
		for a,b in zip(A,B):
				err += (a - b) ** 2
		return np.sum(np.sqrt(err) / len(A))/3

x, y = [], []
with open(argv[1]) as f:
		f.readline()
		f.readline()
		w,h = f.readline().replace("\n", "").split()
		w, h = int(w), int(h)
		f.readline()
		orig = np.array(f.read().replace("\n", " ").split()).astype(np.int).reshape([h*w, 3])
		x.append((avgEucError(orig, orig), 0))
		#y.append(avgEucError(orig, orig))

for var in argv[2:]:
		with open(var) as f:
				for i in range(3):
						f.readline()
				other = np.array(f.read().replace("\n", " ").split()).astype(np.int).reshape([h*w, 3])
				var = float(var[var.find('_') + 1:-4])
				x.append((avgEucError(orig, other), var))
				#y.append(avgEucError(orig, other))

if "ms" == argv[2][0:2]:
		plt.title("Mean-Shift Error Distances based on Mean Squared Error")
elif "wta" == argv[2][0:3]:
		plt.title("Winner-Take-All Error Distances based on Mean Squared Error")
else:
		plt.title(argv[2][0:argv[2].find('_')] + " Error Distances based on Mean Squared Error")
plt.grid()
plt.xlabel("Number of Clusters")
plt.ylabel("Distance")
x = sorted(x, key=itemgetter(1))
a, b = [], []
for var in x:
		a.append(var[0])
		b.append(var[1])
plt.plot(b,a, '-')
plt.show()
