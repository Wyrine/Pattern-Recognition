#!/usr/local/bin/python3

import numpy as np
import matplotlib.pyplot as plt
def perc(x):
		#x0 = -w1 / w0 * x1 + bias/ w0 is the line
		return -1 * x + 1.5

if __name__ == "__main__":
		mm = np.matmul
		tran = np.transpose
		te = [0, 0, 0, 1]
		tr = [[0, 0], [0, 1], [1, 0], [1, 1]]
		plt.title("FLD, PCA, and Perceptron Comparison")
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
#		plt.show()
#		plt.clf()

# PCA
		tr = tran(tr)
		te = tran(te)
#
#		eigs, eigVecs = np.linalg.eig(np.cov(tr))
#		eigVecs = eigVecs[:, 0]
#		pTr = mm(tran(eigVecs), tr)
#
#		plt.plot(pTr[:3], np.zeros(3), "r.")
#		plt.plot(pTr[3], 0, "b.")
		plt.vlines(2/3, -10, 10)
#		plt.show()

# Perceptron
		x = np.linspace(0.1, 1.53)
		plt.plot(tran(tr)[:3, 0], tran(tr)[:3, 1], "g.")
		plt.plot(tran(tr)[3, 0], tran(tr)[3, 1], "r.")
		plt.plot(x, perc(x), "b-")
		plt.show()
