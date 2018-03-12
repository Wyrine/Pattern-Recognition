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
static mutex mtx;

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
protected:
    uint classes, features;
    Matrix X, nX, Xte, nXte, pX, pXte, fX, fXte, fW;
    vector<Matrix> mu, sig, pMu, pSig, fMu, fSig;

    double (*compFunc)(const string &);
    bool getSamp(ifstream &, double []);
    void buildMatrix(vector<Sample> &, Matrix&);
    void readFile(const char*, Matrix &);
    void addLabels(Matrix &, const Matrix &);
    void setParams(vector<Matrix> &, vector<Matrix> &, Matrix &, Matrix &);
    Matrix & getProb(Matrix&, const double [], const vector<Matrix> &,
                        const vector<Matrix> &, Matrix&);
    void generateEvals(const Matrix &, const double[], FILE* out = stdout) const;
		void varyNorm1();
		void varyPCA1();
		void varyFLD1();
public:
    double getProb0() { return ((double) getType(X, 0).getRow() ) / X.getRow(); }
    double getProb1() { return ((double) getType(X, 1).getRow() ) / X.getRow(); }
    Mat(const char*, const char*, const uint&, const uint&, 
            double (*_compFunc)(const string &));

		void varyCase1();
		void varyCase2();
		void varyCase3();
    void runCase1(const double []);
    void runCase2(const double []);
    void runCase3(const double []);
		void varyNorm2();
		void varyPCA2();
		void varyFLD2();
		void varyNorm3();
		void varyPCA3();
		void varyFLD3();
    void PCA(float maxErr = 0.1);
    void FLD();
		void varyProb(const int);
};
