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
	totalElems = 0;
}

Mat::Mat(stringstream _ss, const int _lines, const int _features, const int _classes)
{
	double trX, trY;
	int trL, i; 
	classes = _classes;
	features = _features;
	totalElems = _lines;

	xData.createMatrix(totalElems/classes, classes);
	yData.createMatrix(totalElems/classes, classes);

	for(i = 0; i < totalElems; i++)
	{
		_ss >> trX >> trY >> trL;
		xData(i, 0) = trX;
		yData(i, 0) = trY;
	}
	for(; i < totalElems; i++)
	{
		_ss >> trX >> trY >> trL;
		xData(i, 1) = trX;
		yData(i, 1) = trY;
	}
}


int Mat::getTotal(const int denominator) const
{
	return totalElems/denominator;
}
