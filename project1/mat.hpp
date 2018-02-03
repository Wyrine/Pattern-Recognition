#pragma once
#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <string>
#include <Matrix.h>
#include <Pr.h>
#include <cmath>
#include <fstream>
#include <sstream>


#define PI_CONST 1.0 / pow(2 * M_PI, features/2) 

class Mat
{
	int classes, features;
	Matrix first, second;
	Matrix mu_0, mu_1, firstCov, secondCov;
	int totalElems;

	double getProb(Matrix testData, double prior[], Matrix cov);
public:
	Mat();
	Mat(stringstream &ss, const int lines, const int features,
		const int classes);
	Matrix getMu(const int) const;
	Matrix getCov(const int) const;
	Matrix getMat(const int) const;
	double case1Accuracy(const char* testFile);
};
