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

struct Sample
{
    vector<double> sample;
    Sample(const int& _features, const double samp[])
    {
        for(int i = 0; i < _features; i++)
            sample.push_back(samp[i]);
    }
    double & operator[](const int& i) { return sample[i]; }
};

class Mat
{
    int classes, features;
    //int totalElems;
    //X is original data
    //nX is data post preprocessing
    vector<Matrix> X, nX, mean, cov;
    bool getSamp(ifstream &, double []);
public:
    Mat(const char*, const int&, const int&);
};
