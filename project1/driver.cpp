#include <sstream>
#include <cmath>
#include <Matrix.h>
#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include "Pr.h"
#include "mat.hpp"

using namespace std;

stringstream readTraining(const string fName, int &lines);

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
	Mat trData(ss, d, atoi(argv[3]), atoi(argv[4]));
	trData.case1Accuracy(argv[2]);

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
