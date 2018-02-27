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
    mat.PCA();
    mat.FLD();
    return 0;
}
