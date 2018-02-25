#include <iostream>
#include "mat.hpp"

using namespace std;

Mat::Mat(const char* fName, const int& _features, const int& _classes)
{
    ifstream input(fName);
    vector<Sample> c0, c1; 
    double samp[_features];
    string curClass;

    classes = _classes;
    features = _features;
    if(! input.is_open() )
    {
        fprintf(stderr, "Unable to open %s, exiting.\n", fName);
        exit(1);
    }
    getline(input, curClass);
    while( getSamp(input, samp) )
    {
        Sample s(features, samp);
        input >> curClass;
        if(curClass == "No") c0.push_back(s);
        else c1.push_back(s);
    }    
    input.close();
}

bool
Mat::getSamp(ifstream &input, double samp[])
{
    int i;
    for(i = 0; i < features && (input >> samp[i]); i++);
    if( i < 7) return false;
    return true;
}

ostream& 
operator<<(ostream &os, const Sample &s)
{
    for(int i = 0; i < s.sample.size(); i++)
        os << s.sample[i] << " ";
    os << endl;
    return os;
}
