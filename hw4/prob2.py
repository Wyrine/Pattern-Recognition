#!/usr/local/bin/python3

import numpy as np
import matplotlib.pyplot as plt

def perceptron(te):
		x = np.array([[0, 0], [1, 0], [0, 1], [1, 1]], dtype=np.float64)
		w = [0,0]
		for i in range(10):
				res = []
				for j in range(len(x)):
						prod = np.matmul(np.transpose(w), x[j])
						prod = 1 if prod >= 0.5 else 0
						res.append(prod)
						w[0] = w[0] + (te[j] - prod) * x[j, 0]
						w[1] = w[1] + (te[j] - prod) * x[j, 1] 
				print("\t", res)

if __name__ == "__main__":
		print("~~~~~~~ OR ~~~~~~~~")
		perceptron(np.array([0, 1, 1, 1], dtype=np.float64))

		print("\n\n\n~~~~~~~ XOR ~~~~~~~~")
		perceptron(np.array([0, 1, 1, 0], dtype=np.float64))
