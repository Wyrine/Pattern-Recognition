#pragma once
#include "mat.hpp"

class Validation : public Mat
{
		protected:
				//the different groups of m-fold cross validation
				vector < vector<short> > groups;
				//the data set stored as a vector of samples
				vector<Sample> dataSet; 
				Validation(){}
				//default comparison function used for fglass
				static int mComp(const int);
		public:
				//data file, validation split file
				Validation(const char*, const char*, const uint = 10, const uint = 9, 
								const uint = 6);
				//uint is the number of folds of validation
				void Validate(const uint = 10);
				void readGroupingFile(const char*);
				void readAndBuildMatrix(const char*);
};
