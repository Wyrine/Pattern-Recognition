#include "driver.hpp"

using namespace std;

vector<double> readTraining(const string fName);


int
main(int argc, char** argv)
{
	vector<double> x, y;
	if(argc < 5)
	{
		cerr << "Usage: ./driver trainFile testFile numFeatures numClasses\n";
		return(1);
	}
		
	
	return 0;
}

vector<double>
readTraining(const string fName)
{
	
	vector<double> data;
	string trash;
	ifstream train(fName);
	if(! train.is_open() )
	{
		fprintf(stderr, "Could not open %s, exiting.\n", fName.c_str());
		exit(1);
	}
	//reading in the header line
	train >> trash >> trash >> trash;
	//begin reading data	

	return data;
}
