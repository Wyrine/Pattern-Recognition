/*
Kirolos Shahat
ECE 471
*/

#include <iostream>
#include "mat.hpp"
using namespace std;

Mat::Mat()
{
	classes = features = totalElems = 0;
}

Mat::Mat(stringstream &_ss, const int _lines, const int _features,
		const int _classes)
{
	double trX, trY;
	int trL, i;
	classes = _classes;
	features = _features;
	totalElems = _lines;

	first.createMatrix(totalElems/classes, features);
	second.createMatrix(totalElems/classes, features);

	for(i = 0; i < totalElems/classes; i++)
	{
		_ss >> trX >> trY >> trL;
		first(i, 0) = trX;
		first(i, 1) = trY;
	}
	for(i = 0; i < totalElems/classes; i++)
	{
		_ss >> trX >> trY >> trL;
		second(i, 0) = trX;
		second(i, 1) = trY;
	}
	//get mu for x and y
	mu_0 = mean(first, classes);
	mu_1 = mean(second, classes);
	firstCov = cov(first, features);
	secondCov = cov(second, features);
}


Matrix
Mat::getMu(const int choice) const
{
	return (choice > 0 ) ? mu_1 : mu_0;
}

Matrix
Mat::getCov(const int choice) const
{
	return (choice > 0 ) ? firstCov : secondCov;
}

Matrix
Mat::getMat(const int choice) const
{
	return ( choice > 0 ) ? second : first;
}

double
Mat::case1Accuracy(const char* testFile)
{
	Matrix testData = readData(testFile, features + 1);
    Matrix identity(features, features);
	double prior[classes];
    for(int i = 0; i < features; i++)
        identity(i, i) = 1.0;
	for(int i = 0; i < classes; i++)
		prior[i] = 1.0/classes;

	return getProb(testData, prior, firstCov(0, 0)* identity);
}

double
Mat::getProb(Matrix testData, double prior[], Matrix cov)
{
	Matrix xVec(features, 1), diff;

	int samples = testData.getRow() - 1, choice;
	double post[classes], accuracy = 0.0;

	for(int i = 1; i < samples; i++)
	{
		for(int j = 0; j < features; j++)
			xVec(0, j) = testData(i, j);
        //if the mu_0/1 matrices can get combined then this can become a loop and
        //thus more generic. That will be a goal later.
        diff = xVec - mu_0;
        post[0] = PI_CONST * 1 / sqrt(det(cov)) * prior[0];
        post[0] *= exp(- mtod(transpose(diff) ->* inverse(cov) ->* diff) / 2.0);
       
        diff = xVec - mu_1;
        post[1] = PI_CONST * 1.0 / sqrt(det(cov)) * prior[1];
        post[1] *= exp(- mtod(transpose(diff) ->* inverse(cov) ->* diff) / 2.0);
        
        choice = (post[0] > post[1]) ? 0 : 1;
        if(testData(i, features) == choice) accuracy++;
	}
	return accuracy/samples;
}
