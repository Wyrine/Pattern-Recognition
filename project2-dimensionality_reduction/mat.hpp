#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>
#include "Matrix.h"
#include "Pr.h"


#define STEP_SIZE 0.000005
#define PI_CONST 1.0 / pow(2*M_PI, features/2)
typedef unsigned int uint;

struct Sample
{
    vector<double> sample;
    Sample(const uint& _features, const double samp[])
    {
        for(int i = 0; i < _features; i++)
            sample.push_back(samp[i]);
    }
    double & operator[](const int& i) { return sample[i]; }
    friend ostream & operator<<(ostream &, const Sample &);
};

class Mat
{
    uint classes, features;
    //int totalElems;
    vector<Matrix> dataSet, mean, cov;
    bool getSamp(ifstream &, double []);
    void buildMatrix(vector<Sample> &);
public:
    Mat(const char*, const uint&, const uint&, bool pp);
};
