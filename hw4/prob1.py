#!/usr/local/bin/python3

import numpy as np
import matplotlib.pyplot as plt
def f(x):
		return 50*np.sin(x)+ x*x

def fP(x):
		return 50*np.cos(x) + 2*x

def gd(t, c, eps):
		steps = [t]
		while True:
				t2 = t - c * fP(t)	
				steps.append(t2)
				if np.abs(t2 - t) < eps:
						return np.array(steps)
				t = t2

if __name__ == "__main__":
		x = np.linspace(-10,10)
#problem 1.a
		plt.title("Problem 1.a")
		plt.plot(x, f(x), "b-")
		plt.xlim([-10,10])
		plt.show()
		plt.clf()

#problem 1.b.i
		plt.title("Problem 1.b.i with learning rate 0.01")
		plt.plot(x, f(x), "b-")
		plt.xlim([-10, 10])
		sols = gd(7, 0.01, 10e-3)
		ySols = f(sols)
		plt.plot(sols, ySols, "r.")
		plt.show()
		plt.clf()

#problem 1.b.ii
		plt.title("Problem 1.b.ii with learning rate 0.01")
		plt.plot(x, f(x), "b-")
		plt.xlim([-10,10])
		sols = gd(1, 0.01, 10e-3)
		plt.plot(sols, f(sols), "r.")
		plt.show()
		plt.clf()

#problem 1.b.iii
		plt.title("Problem 1.b.iii with learning rate 0.1")
		plt.plot(x, f(x), "b-")
		plt.xlim([-10,10])
		sols = gd(7, 0.1, 10e-3)
		plt.plot(sols, f(sols), "r.")
		plt.show()
		plt.clf()
