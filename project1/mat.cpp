/*
Kirolos Shahat
ECE 471
Maximum Likelihood Estimate
*/

#include <iostream>
#include "mat.hpp"
using namespace std;

Mat::Mat()
{
	classes = features = totalElems = 0;
}

Mat::Mat(stringstream &_ss, const int _lines, const int _features, const int _classes)
{
	double trX, trY;
	int trL, i; 
	yMu.createMatrix(_features);
	classes = _classes;
	features = _features;
	totalElems = _lines;

	xData.createMatrix(totalElems/classes, classes);
	yData.createMatrix(totalElems/classes, classes);

	for(i = 0; i < totalElems/classes; i++)
	{
		_ss >> trX >> trY >> trL;
		xData(i, 0) = trX;
		yData(i, 0) = trY;
	}
	for(i = 0; i < totalElems/classes; i++)
	{
		_ss >> trX >> trY >> trL;
		xData(i, 1) = trX;
		yData(i, 1) = trY;
	}
	//get mu for x and y
	xMu = mean(xData, classes);
	yMu = mean(yData, classes);
	xCov = cov(xData, features);
	yCov = cov(yData, features);
}
