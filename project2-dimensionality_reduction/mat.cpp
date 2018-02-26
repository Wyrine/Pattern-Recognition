#include <iostream>
#include "mat.hpp"

using namespace std;

Mat::Mat(const char* fName, const uint& _features, const uint& _classes,
            double (*_compFunc)(const string &))
{
    ifstream input(fName);
    vector<Sample> d; 
    double samp[_features+1];
    string tmp;

    classes = _classes;
    features = _features;
    compFunc = _compFunc;

    if(! input.is_open() )
    {
        fprintf(stderr, "Unable to open %s, exiting.\n", fName);
        exit(1);
    }
    getline(input, tmp);
    while( getSamp(input, samp) )
    {
        Sample s(features, samp);
        d.push_back(s);
    }
    input.close();

    buildMatrix(d);
}

bool
Mat::getSamp(ifstream &input, double samp[])
{
    int i;
    string tmp;

    for(i = 0; i < features && (input >> samp[i]); i++);
    if( i < features) return false;

    input >> tmp;
    samp[i] = compFunc(tmp);
    
    return true;
}

void
Mat::buildMatrix(vector<Sample> &c)
{
    int sz = c.size();
    X.createMatrix(sz, features+1);
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < features + 1; j++)
            X(i, j) = c[i][j];
    //should make this it's own function
    for(int i = 0; i < classes; i++)
    {
        Matrix t2 = getType(X, i);
        mu.push_back(mean(t2, features));
        sig.push_back(cov(t2, features));
    }
    nX = X;
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < features; j++)
            nX(i, j) = ( X(i, j) - mu[X(i, features)](j, 1)) 
                        / sqrt( sig[X(i, features)] (j, j));
    cout << nX;
}


ostream& 
operator<<(ostream &os, const Sample &s)
{
    for(int i = 0; i < s.sample.size(); i++)
        os << s.sample[i] << " ";
    os << endl;
    return os;
}
