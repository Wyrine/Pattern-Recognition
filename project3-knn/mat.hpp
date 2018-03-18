#pragma once

#define _USE_MATH_DEFINES

#include <iostream>
#include <cstdlib>
#include <string>
#include <cmath>
#include <fstream>
#include <thread>
#include <vector>
#include "Matrix.h"
#include "Pr.h"


#define STEP_SIZE 0.1
#define PI_CONST 1.0 / pow(2*M_PI, (testData.getCol() - 1 )/2)
#define STORAGE_PATH "./performance/"
typedef unsigned int uint;

int normalize(Matrix &, Matrix &, const int, const int);
int pca(Matrix &, Matrix &, const int, const float, const int);
Matrix Identity(const uint);

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

				Mat(){ classes=features=0; compFunc = nullptr; }
				double (*compFunc)(const string &);
				virtual bool getSamp(ifstream &, double []);
				virtual void buildMatrix(vector<Sample> &, Matrix&);
				virtual void readFile(const char*, Matrix &);
				void addLabels(Matrix &, const Matrix &);
				void setParams(vector<Matrix> &, vector<Matrix> &, Matrix &, Matrix &);
				Matrix & MPP(Matrix&, const double [], const vector<Matrix> &,
								const vector<Matrix> &, Matrix&);
				Matrix kNN(const Matrix &, const Matrix &, const uint, const uint) const;
				static double Minkowski(const Matrix &, const Matrix &, const uint dist = 2);
				static void generateEvals(const Matrix &, const void*, FILE* = stdout, const uint = 0);
				static FILE* openFile(const char*);
				static Matrix cropMatrix(const Matrix &, const uint, const uint,
								const uint, const uint);
				static void writeHeader(const uint, FILE* = stdout, const uint = 0);
				virtual void varyNorm1();
				virtual void varyPCA1();
				virtual void varyFLD1();
				virtual void varyNorm2();
				virtual void varyPCA2();
				virtual void varyFLD2();
				virtual void varyNorm3();
				virtual void varyPCA3();
				virtual void varyFLD3();
				short neighborVoting(const Matrix &) const;
		public:
				virtual double prior0() { return ((double) getType(X, 0).getRow() ) / X.getRow(); }
				virtual double prior1() { return ((double) getType(X, 1).getRow() ) / X.getRow(); }
				Mat(const char*, const char*, const uint&, const uint&, 
								double (*_compFunc)(const string &));
				virtual void varyCase1();
				virtual void varyCase2();
				virtual void varyCase3();
				virtual void varykNN(const uint transType, const uint dist = 2);
				virtual void varyAllkNN(const uint dist = 2);
				virtual void varyAllCases();
				virtual void runCase1(const double []);
				virtual void runCase2(const double []);
				virtual void runCase3(const double []);
				virtual void runkNN(const uint = 0, const uint = 3, const uint = 2, FILE* = stdout);
				virtual void PCA(float maxErr = 0.1);
				virtual void FLD();
};
