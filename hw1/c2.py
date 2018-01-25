#!/usr/local/bin/python3

import matplotlib.pyplot as plt
import numpy as np
import matplotlib.mlab as mlab

#original
x = np.linspace(-20,16, 100)
plt.plot(x,mlab.normpdf(x,4,2))
plt.plot(x,mlab.normpdf(x,6,3))
plt.plot(x,mlab.normpdf(x,5,2))
plt.axvline(x=4.7,color = "black")
plt.xticks()
plt.show()

# 1 decision region dominates
x = np.linspace(-10,20, 100)
plt.plot(x,0.6*mlab.normpdf(x,4,2)) #std of 5 generates one decision region, all else unchanged
plt.plot(x,0.2*mlab.normpdf(x,6,3))
plt.plot(x,0.2*mlab.normpdf(x,5,2))
plt.axvline(x=4.7,color = "black")
plt.xticks()
plt.show()

#somehow generates 2 decision regions
x = np.linspace(-10,20, 100)
plt.plot(x,0.6*mlab.normpdf(x,4,(10/2)-2)) 
plt.plot(x,0.2*mlab.normpdf(x,6,(10/6)+2))
plt.plot(x,0.2*mlab.normpdf(x,5,(10/6)+1))
plt.axvline(x=4.7,color = "black")
plt.xticks()
plt.show()
