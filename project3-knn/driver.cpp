#include <iostream>
#include "mat.hpp"

using namespace std;

		double
compareFunc(const string &curStr)
{
		return (curStr == "No") ? 0 : 1;
}

		int
main(int argc, char** argv)
{
		if(argc < 5)
		{
				cerr << "Usage: ./driver trainFile testFile numFeatures numClasses\n";
				return(1);
		}
		Mat mat(argv[1], argv[2], atoi(argv[3]), atoi(argv[4]), compareFunc);
		double prior[atoi(argv[4])]; 
		prior[0] = mat.prior0();
		prior[1] = mat.prior1();
		mat.runkNN(3, 2, 0);
		cout << "Prior from data set: \n\n";
		mat.runCase1(prior);
		mat.runCase2(prior);
		mat.runCase3(prior);

		cout << "Varying Prior probailities and writing to files\n"; 
		mat.varyAllCases();
		cout << "Done\n"; 

		return 0;
}
