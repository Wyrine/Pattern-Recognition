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
    double prior[atoi(argv[4])]; //= {mat.getProb0(), mat.getProb1()};
    prior[0] = mat.getProb0();
    prior[1] = mat.getProb1();
    mat.PCA();
    mat.FLD();
    cout << "Prior from data set: \n\n";
    mat.runCase1(prior);
    mat.runCase2(prior);
    mat.runCase3(prior);
    cout << "Varying Prior probailities\n\n"; 
    for(double i = STEP_SIZE; i < 1.0; i+= STEP_SIZE)
    {
        prior[0] = i;
        prior[1] = 1 - i;
        cout << "Prior for class 0: " << i << " and prior for class 1: " << 1 - i << endl;
        mat.runCase1(prior);
        mat.runCase2(prior);
        mat.runCase3(prior);
    }
    return 0;
}
