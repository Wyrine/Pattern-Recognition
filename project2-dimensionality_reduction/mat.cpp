#include <iostream>
#include "mat.hpp"


using namespace std;

Mat::Mat(const char* fName, const int& _features, const int& _classes)
{
    ifstream input(fName, ifstream::ate);

    classes = _classes;
    features = _features;
    if(! input.is_open() )
    {
        fprintf(stderr, "Unable to open %s, exiting.\n", fName);
        exit(1);
    }
    cerr << input.tellg() / (7*4);
    input.close();
}
