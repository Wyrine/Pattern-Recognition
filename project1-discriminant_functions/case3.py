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
    x = np.concatenate((xTe, xTe1))
    #need to write a function that generates a ton of points 
    #x and y based off of a function so that I can use it for the line and such
    case1Line, = plt.plot(x, 1/1424422 * (-1 * np.sqrt(-2447508099 * (x ** 2) \
                - 3145952122488 * x + 5249167758220) -913123 * x + 2977770), \
                '-', label= "Decision Region for Case 3.")
    plt.legend(handles = [train0, train1, test0, test1, case1Line])
    plt.xlabel('x')
    plt.ylabel('y')
    plt.title("Decision Regions for Case 3")
    plt.grid()
    plt.text(-1.3, -0.22,"y = 1/1424422 * (-1 * sqrt(-2447508099*x^2 -3145952122488*x + 5249167758220) -913123*x +2977770)",color="black")
    plt.show()
