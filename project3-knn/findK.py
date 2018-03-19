#!/usr/local/bin/python3

import pandas as pd
import numpy as np
import sys


if __name__ == "__main__":
		print("Validation row as test, best k value, Matching accuracy")
		for i in range(1, len(sys.argv)):
				df = pd.read_csv(sys.argv[i])
				key = sys.argv[i].replace(".csv", "").replace("performance/", "")
				maxIndex = df["Accuracy"].idxmax()
				bestAcc = df["Accuracy"][maxIndex]
				bestK = df["k"][maxIndex]
		
				print(key, (bestK, bestAcc) )
