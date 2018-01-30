#include <iostream>
#include <vector>
#include <cstdlib>
#include <string>
#include <fstream>
#include "mle.hpp"

using namespace std;

vector<double> readTraining(const string fName);


int
main(int argc, char** argv)
{
	// ./driver train test numFeatures numclasses
	if(argc < 5)
	{
		cerr << "Usage: ./driver trainFile testFile numFeatures numClasses\n";
		return(1);
	}
	
	vector<double> x, y;
	
	return 0;
}

vector<double>
readTraining(const string fName)
{
	vector<double> data;
	ifstream train(fName.c_str());
	if(! train.is_open())
	{
		fprintf(stderr, "Could not open %s, exiting.\n", fName.c_str());
	}

	return data;
}
