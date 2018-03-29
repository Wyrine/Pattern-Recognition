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
		mm = np.matmul
		tran = np.transpose
		te = [0, 0, 0, 1]
		tr = [[0, 0], [0, 1], [1, 0], [1, 1]]

# FLD
		s0 = 2 * np.cov(tran(tr[:3]))
		s1 = 0 * np.cov(tran(tr[3]))
		mu0 = np.array([1/3, 1/3])
		mu1 = np.array([1, 1])
		w = mm(np.linalg.inv(s0 + s1), (mu0 - mu1))
		fTr = np.matmul(tran(w), tran(tr))
		mu0, mu1 = mm(w, tran(mu0)), mm(w, tran(mu1))

		plt.vlines((mu0 + mu1)/2, -10, 10)
		plt.plot(fTr[:3], np.zeros(3),  "b.")
		plt.plot(fTr[3], np.zeros(1), "r.")
		plt.show()
		plt.clf()

# perceptron
		
