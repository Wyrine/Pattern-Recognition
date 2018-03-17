#pragma once
#include "mat.hpp"

class Validation : public Mat
{
		protected:
				vector < vector<short> > groups;
				Validation(){}
		public:
				//data file, validation split file
				Validation(const char*, const char*);
				//uint is the number of folds of validation
				void Validate(const uint = 10);
				void readGroupingFile(const char*);
				void readAndBuildMatrix(const char*);
};
