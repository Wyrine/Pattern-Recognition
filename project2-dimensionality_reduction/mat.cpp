#include <iostream>
#include "mat.hpp"

using namespace std;

Mat::Mat(const char* tr, const char* te, const uint& _features, 
            const uint& _classes, double (*_compFunc)(const string &))
{

    classes = _classes;
    features = _features;
    compFunc = _compFunc;
    readFile(tr, X);
    readFile(te, Xte);
    nX = X;
    nXte = Xte;
    normalize(nX, nXte, 7, 1);

    for(int i = 0; i < classes; i++)
    {
        Matrix t2 = getType(nX, i);
        mu.push_back(mean(t2, features));
        sig.push_back(cov(t2, features));
    }
}

void
Mat::readFile(const char* fName, Matrix &_X)
{
    vector<Sample> d;
    double samp[features+1];
    string tmp;
    ifstream input(fName);

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
    buildMatrix(d, _X);
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
Mat::buildMatrix(vector<Sample> &c, Matrix & _X)
{
    int sz = c.size();
    _X.createMatrix(sz, features+1);
    for(int i = 0; i < sz; i++)
        for(int j = 0; j < features + 1; j++)
            _X(i, j) = c[i][j];
}

Matrix &
Mat::PCA(const double &maxErr) const
{
    Matrix rv = X;
    return rv;
}

ostream& 
operator<<(ostream &os, const Sample &s)
{
    for(int i = 0; i < s.sample.size(); i++)
        os << s.sample[i] << " ";
    os << endl;
    return os;
}
