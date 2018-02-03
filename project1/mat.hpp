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
#include <vector>

#define STEP_SIZE 0.00005
#define PI_CONST 1.0 / pow(2 * M_PI, features/2) 

class Mat
{
	int classes, features;
	Matrix first, second;
	Matrix mu_0, mu_1, firstCov, secondCov;
	int totalElems;

	double getProb(Matrix testData, double prior[], Matrix cov) const;
public:
	Mat();
	Mat(stringstream &ss, const int lines, const int features,
		const int classes);
	Matrix getMu(const int) const;
	Matrix getCov(const int) const;
	Matrix getMat(const int) const;
	double case1Accuracy(const char* testFile) const;
	double case2Accuracy(const char* testFile) const;
	double case3Accuracy(const char* testFile) const;
    vector<double> generatePriorList(const char* testFile) const; 
};
