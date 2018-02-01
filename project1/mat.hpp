#pragma once

#include <iostream>
#include <cstdlib>
#include <string>
#include <Matrix.h>
#include <fstream>
#include <sstream>

class Mat 
{	
	int classes, features;
	Matrix xData, yData;
	Matrix xMu, yMu, xCov, yCov;
	int totalElems;
public:
	Mat();
	Mat(stringstream &ss, const int lines, const int features, const int classes);
};
