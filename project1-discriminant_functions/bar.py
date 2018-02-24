#!/usr/local/bin/python3

import numpy as np
import matplotlib.pyplot as plt

if __name__ == "__main__":
    cases = (1, 2, 3) #y_pos
    xVals = np.array([0.712, 0.884, 0.891])
    plt.xlabel('Case Number( 1 to 3 from left to right respectively)')
    plt.ylabel('Accuracy')
    plt.title("Decision Regions for Case 3")
    plt.bar(cases, xVals)
    plt.text(0.8, 0.651, "0.712", color="black")
    plt.text(1.8, 0.651, "0.884", color="black")
    plt.text(2.8, 0.651, "0.891", color="black")
    plt.show()
