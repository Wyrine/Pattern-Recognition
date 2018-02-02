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

Matrix Mat::getMu(const int choice) const
{
	return (choice > 0 ) ? mu_1 : mu_0;
}

Matrix Mat::getCov(const int choice) const
{
	return (choice > 0 ) ? firstCov : secondCov;
}

Matrix Mat::getMat(const int choice) const
{
	return ( choice > 0 ) ? second : first;
}

