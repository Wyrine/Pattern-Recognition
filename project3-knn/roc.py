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
