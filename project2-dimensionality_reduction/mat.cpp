#include <iostream>
#include "mat.hpp"


using namespace std;

Mat::Mat(const char* fName, const int& _features, const int& _classes)
{
    classes = _classes;
    features = _features;
    dataSet = readData(fName, features+1);
    cout << dataSet;

}
