#include "driver.hpp"

using namespace std;

void readTraining(const string fName);


int
main(int argc, char** argv)
{
	if(argc < 5)
	{
		cerr << "Usage: ./driver trainFile testFile numFeatures numClasses\n";
		return(1);
	}
	readTraining(argv[1]);
	return 0;
}

void
readTraining(const string fName)
{
	
	Matrix z;
	string trash;
	short curLabel;
	double x, y;
	ifstream train(fName);

	if(! train.is_open() )
	{
		cerr << "Could not open " << fName << ", exiting.\n";
		exit(1);
	}
	//reading in the header line
	train >> trash >> trash >> trash;
	//begin reading data
	//d.totalElems = 0;
	while(train >> x)
	{
		train >> y >> curLabel;
		//d.x.push_back(x);
		//d.y.push_back(y);
		//d.label.push_back(curLabel);
		//d.totalElems++;
	}	
	//train.close();
}
