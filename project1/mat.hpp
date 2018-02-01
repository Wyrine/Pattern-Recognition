#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <Matrix.h>
#include <fstream>
#include <sstream>

class Mat 
{	
	Matrix xData, yData;
	Matrix xMu, yMu;
	int classes;
	int features;
	int totalElems;
public:
	Mat();
	Mat(stringstream &ss, const int lines, const int features, const int classes);
	int getTotal(const int denominator = 1) const;
};
