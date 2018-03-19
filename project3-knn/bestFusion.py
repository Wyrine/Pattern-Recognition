#!/usr/local/bin/python3

import pandas as pd
import numpy as np
import sys


if __name__ == "__main__":
		for i in range(1, len(sys.argv)):
				df = pd.read_csv(sys.argv[i])
				maxIndex = df["Accuracy"].idxmax()
				print(df.ix[maxIndex])
