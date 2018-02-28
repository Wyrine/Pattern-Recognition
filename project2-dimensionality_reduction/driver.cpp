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
    for( int i = 0; i < atoi(argv[4]); i++)
        prior[i] = 1.0/ atoi(argv[4]);
    mat.PCA();
    mat.FLD();
    mat.runCase1(prior);
    mat.runCase2(prior);
    mat.runCase3(prior);
    return 0;
}
