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
	Matrix first, second;
	Matrix mu_0, mu_1, firstCov, secondCov;
	int totalElems;
public:
	Mat();
	Mat(stringstream &ss, const int lines, const int features,
		const int classes);
};
