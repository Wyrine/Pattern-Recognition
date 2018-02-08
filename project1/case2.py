#!/usr/local/bin/python3

import numpy as np
import matplotlib.pyplot as plt
from case1 import getData

if __name__ == "__main__":
    xTr, yTr, xTr1, yTr1, xTe, yTe, xTe1, yTe1 = getData("./data/synth.tr", "./data/synth.te")
    train0, = plt.plot(xTr, yTr, 'r.', label="Training Data, Class 0")
    train1, = plt.plot(xTr1, yTr1, 'g.', label="Training Data, Class 1")
    test0, = plt.plot(xTe, yTe, 'c.', label="Testing Data, Class 0")
    test1, = plt.plot(xTe1, yTe1, 'y.', label="Testing Data, Class 1")
    test = np.concatenate((xTe, xTe1))
    m, b = -0.0704584, 0.499236
    #need to write a function that generates a ton of points 
    #x and y based off of a function so that I can use it for the line and such
    case1Line, = plt.plot(test, m * test + b, '-', label= "Decision Region for Case 2.")
    plt.legend(handles = [train0, train1, test0, test1, case1Line])
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title("Decision Regions for Case 2")
    plt.grid()
    plt.text(-1.34, 0.7187, "y = -0.0704584x + 0.499236", color="black")
    plt.show()
