#!/usr/local/bin/python3

import pandas as pd
import numpy as np
import sys


if __name__ == "__main__":
		for i in range(1, len(sys.argv)):
				df = pd.read_csv(sys.argv[i])
				df.sort_values(by="Accuracy", ascending = False, inplace = True)
				key = sys.argv[i].replace(".csv", "").replace("performance/", "")
				print(key + "\n", df[["k", "dist", "Accuracy"]][:4])
