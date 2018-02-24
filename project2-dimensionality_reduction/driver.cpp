#include <iostream>
#include "mat.hpp"

using namespace std;

int
main(int argc, char** argv)
{
    if(argc < 5)
    {
        cerr << "Usage: ./driver trainFile testFile numFeatures numClasses\n";
        return(1);
    }
    Mat mat(argv[1], atoi(argv[3]), atoi(argv[4]));


    return 0;
}
