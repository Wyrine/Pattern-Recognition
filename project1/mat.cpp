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

int
Mat::case1Accuracy(const char* testFile)
{
	Matrix testData = readData(testFile, features + 1);
	double prior[classes];
	int count, i;

	for(i = 0; i < classes; i++)
		prior[i] = 1.0/classes;

	getProb(testData, prior, firstCov(0, 0));
	return 0;
}

double
Mat::getProb(Matrix testData, double prior[], double cov)
{
	Matrix identity(features,features);
	Matrix xVec(features, 1);
	int samples = testData.getRow() - 1, count = 0, index = 0, prev = -1;
	double post[classes];

	for(int i = 0; i < features; i++) identity(i, i) = 1;
	identity =  cov * identity;
	for(int i = 1; i < samples; i++)
	{
		for(int j = 0; j < features; j++)
			xVec(0, j) = testData(i, j);
        
        Matrix dif = xVec - mu_0;
	    post[0] = exp(- pow(mtod(transpose(dif) ->* dif), 2) / (2.0 * cov) + log(prior[0]));
	    //post[0] = exp(- pow(mtod(transpose(dif) ->* dif), 2) / (2.0 * cov) + log(prior[0])) * 1.0/ (2.0 * cov * M_PI) ;
        cout << post[0] << endl;
        dif = xVec - mu_1;
	    post[1] = exp(- pow(mtod(transpose(dif) ->* dif), 2) / (2.0 * cov) + log(prior[1]));
	    //post[1] = exp(- (mtod(transpose(dif) ->* dif), 2) / (2.0 * sqrt(cov))) *
                    //prior[1] * 1.0/ (2.0 * cov * M_PI) ;
	    //post[1] = - mtod(transpose(dif) ->* dif) / (2 * cov) + log(prior[1]);
        cout << post[1] << endl;
        exit(1);

	}
    cout << count << " | " << samples;
	return count/samples;
}
