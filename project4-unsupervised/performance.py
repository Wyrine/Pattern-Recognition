#!/usr/local/bin/python3

import matplotlib.pyplot as plt
from sys import argv
import numpy as np

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
		x.append(0)
		y.append(avgEucError(orig, orig))

for var in argv[2:]:
		with open(var) as f:
				for i in range(3):
						f.readline()
				other = np.array(f.read().replace("\n", " ").split()).astype(np.int).reshape([h*w, 3])
				var = int(var[var.find('_') + 1:-4])
				x.append(var)
				y.append(avgEucError(orig, other))

plt.title(argv[1][:-4])
plt.grid()
plt.plot(x,y, '-')
plt.show()
