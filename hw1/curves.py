#!/usr/local/bin/python3

import matplotlib.pyplot as plt
import numpy as np
import matplotlib.mlab as mlab
import math

mu = 0
variance = 1
sigma = math.sqrt(variance)
x = np.linspace(-5,16, 100)
plt.plot(x,0.6 * mlab.normpdf(x,4,2))
plt.plot(x,0.2 * mlab.normpdf(x,6,3))
plt.plot(x,0.2 * mlab.normpdf(x,5,2))
plt.axvline(x=4.7,color = "black")
plt.xticks()
plt.show()
