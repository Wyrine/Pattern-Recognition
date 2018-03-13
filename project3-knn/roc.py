#!/usr/local/bin/python3

import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import sys

if __name__ == "__main__":
		if len(sys.argv) < 2:
				print("Usage: ./roc.py performanceFile.csv")
				sys.exit(1)
		df = pd.read_csv(sys.argv[1])
		tpr = np.array(df["Sensitivity(Recall)"])
		fp, tn = np.array(df["FP"]), np.array(df["TN"])
		ind = sys.argv[1].find("/")
		title = sys.argv[1][ind+1:].replace(".csv", "")

		fpr = np.zeros(len(fp), dtype=np.float64)
		for i in range(len(fp)):
				fpr[i] = fp[i] / (fp[i] + tn[i])

		plt.title(title)
		plt.xlabel("False Positive Rate")
		plt.ylabel("True Positive Rate")
		plt.xlim([0.0, 1.0])
		plt.ylim([0.0, 1.0])
		plt.plot(fpr, tpr)
		plt.show()
