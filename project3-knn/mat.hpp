#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
#include <thread>
#include <mutex>
#include <vector>
#include "Matrix.h"
#include "Pr.h"


#define STEP_SIZE 0.1
#define PI_CONST 1.0 / pow(2*M_PI, (testData.getCol() - 1 )/2)
typedef unsigned int uint;

int normalize(Matrix &, Matrix &, const int, const int);
int pca(Matrix &, Matrix &, const int, const float, const int);

struct Sample
{
    vector<double> sample;
    Sample(const uint& _features, const double samp[])
    {
        for(int i = 0; i < _features + 1; i++)
            sample.push_back(samp[i]);
    }
    double & operator[](const int& i) { return sample[i]; }
    friend ostream & operator<<(ostream &, const Sample &);
};

class Mat
{
    uint classes, features;
    Matrix X, nX, Xte, nXte, pX, pXte, fX, fXte, fW;
    vector<Matrix> mu, sig, pMu, pSig, fMu, fSig;
		mutex mtx;

    double (*compFunc)(const string &);
    bool getSamp(ifstream &, double []);
    void buildMatrix(vector<Sample> &, Matrix&);
    void readFile(const char*, Matrix &);
    void addLabels(Matrix &, const Matrix &);
    void setParams(vector<Matrix> &, vector<Matrix> &, Matrix &, Matrix &);
    Matrix & getProb(Matrix&, const double [], const vector<Matrix> &,
                        const vector<Matrix> &, Matrix&);
    void generateEvals(const Matrix &, FILE* out = stdout) const;
public:
    double getProb0() { return ((double) getType(X, 0).getRow() ) / X.getRow(); }
    double getProb1() { return ((double) getType(X, 1).getRow() ) / X.getRow(); }
    Mat(const char*, const char*, const uint&, const uint&, 
            double (*_compFunc)(const string &));

    void runCase1(const double [], double pr0 = 0, double pr1 = 0);
    void runCase2(const double [], double pr0 = 0, double pr1 = 0);
    void runCase3(const double [], double pr0 = 0, double pr1 = 0);
		void varyNorm1();
    void PCA(float maxErr = 0.1);
    void FLD();
		void varyProb(const int);
};
