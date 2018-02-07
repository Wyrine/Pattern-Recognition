#!/usr/local/bin/python3

import numpy as np
import matplotlib.pyplot as plt

def getData(tr, te):
    xTr, yTr, xTr1, yTr1 = [], [], [], []
    xTe, yTe = [], []
    xTe1, yTe1 = [], []
    with open(tr) as f:
        f.readline()
        data = f.read().replace("\n", " ").split(" ")
    with open(te) as f:
        f.readline()
        testData = f.read().replace("\n", " ").split(" ")
    data[:] = (float(value) for value in data if value != "")
    testData[:] = (float(value) for value in testData if value != "")

    for i in range(0, len(data), 3):
        if data[i+2] == 0:
            xTr.append(data[i])
            yTr.append(data[i+1])
        else:
            xTr1.append(data[i])
            yTr1.append(data[i+1])
        
    for i in range(0, len(testData), 3):
        if testData[i+2] == 0:
            xTe.append(testData[i])
            yTe.append(testData[i+1])
        else:
            xTe1.append(testData[i])
            yTe1.append(testData[i+1])
    
    xTr, yTr, xTr1, yTr1 = np.array(xTr), np.array(yTr), np.array(xTr1), np.array(yTr1) 
    xTe, yTe = np.array(xTe), np.array(yTe) 
    xTe1, yTe1 = np.array(xTe1), np.array(yTe1) 
    
    return xTr, yTr, xTr1, yTr1, xTe, yTe, xTe1, yTe1 

def generateFunc( eq ):
    xVals = np.linspace(-100, 100, 1)
    yVals = eq(xVals)
    return xVals, yVals


if __name__ == "__main__":
    xTr, yTr, xTr1, yTr1, xTe, yTe, xTe1, yTe1 = getData("./data/synth.tr", "./data/synth.te")
    plt.plot(xTr, yTr, 'r.')
    plt.plot(xTr1, yTr1, 'g.')
    plt.plot(xTe, yTe, 'k.')
    plt.plot(xTe1, yTe1, 'k.')
    test = np.concatenate((xTe, xTe1))
    print(test)
    m, b = -0.832623, 0.443782
    #need to write a function that generates a ton of points 
    #x and y based off of a function so that I can use it for the line and such
    plt.plot(test, m * test + b, '-')
    plt.grid()
    plt.show()
