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

class Mat
{
    int classes, features, totalElems;
    Matrix dataSet;
    vector<Matrix> mean, cov;
    
public:
    Mat(const char*, const int&, const int&);
};
