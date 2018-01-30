#include "driver.hpp"

using namespace std;

Data readTraining(const string fName);


int
main(int argc, char** argv)
{
	Data d;
	if(argc < 5)
	{
		cerr << "Usage: ./driver trainFile testFile numFeatures numClasses\n";
		return(1);
	}
	d = readTraining(argv[1]);
	return 0;
}

Data
readTraining(const string fName)
{
	
	Data d; 
	string trash;
	short curLabel;
	double x,y;
	ifstream train(fName);

	if(! train.is_open() )
	{
		fprintf(stderr, "Could not open %s, exiting.\n", fName.c_str());
		exit(1);
	}
	//reading in the header line
	train >> trash >> trash >> trash;
	//begin reading data
	d.totalElems = 0;
	while(train >> x)
	{
		train >> y >> curLabel;
		d.x.push_back(x);
		d.y.push_back(y);
		d.label.push_back(curLabel);
		d.totalElems++;
	}	
	train.close();
	return d;
}
