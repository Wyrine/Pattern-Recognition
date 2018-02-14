#!/usr/local/bin/python3
import matplotlib.pyplot as plt
import numpy as np

x1 = np.array([[0.8, 0.9, 1.2, 1.1],[1.2, 1.4, 1.4, 1.5]])
y1 = np.array([1.2, 1.4, 1.4, 1.5])
x2 = np.array([[0.8, 0.6, 0.65, 0.75], [1.1, 1, 1.1, 0.9]])

plt.contour(x1, x2)
plt.show()
