#include <sstream>
#include <cmath>
#include <Matrix.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include <Pr.h>
#include "mat.hpp"

using namespace std;

stringstream readTraining(const string fName, int &lines);
Matrix buildMat(stringstream ss, const int lines, const int features, const int classes);

int
main(int argc, char** argv)
{
	int d = 0;
	stringstream ss;
	if(argc < 5)
	{
		cerr << "Usage: ./driver trainFile testFile numFeatures numClasses\n";
		return(1);
	}
	ss = readTraining(argv[1], d);
	return 0;
}

stringstream
readTraining(const string fName, int &lines)
{
	string trash;
	stringstream ss;
	ifstream train(fName);

	if(! train.is_open() )
	{
		cerr << "Could not open " << fName << ", exiting.\n";
		exit(1);
	}
	//reading in the header line
	getline(train, trash);
	while(getline(train, trash))
	{
		ss << trash << " ";
		lines++;
	}
	train.close();
	return ss;
}

Matrix
buildMat(stringstream ss, const int lines, const int features, const int classes)
{
	double trX, trY;
	int trL, i;
	
	Matrix xData(lines/2, classes), yData(lines/2, classes);
	for(i = 0; i < lines/2; i++)
	{
		ss >> trX >> trY >> trL;
		xData(i, 0) = trX;
		yData(i, 0) = trY;
	}
	for(; i < lines; i++)
	{
		ss >> trX >> trY >> trL;
		xData(i, 1) = trX;
		yData(i, 1) = trY;
	}
		
	return xData;
}
