#pragma once
#include "mat.hpp"

class Validation : public Mat
{
		public:
				Validation();
				//data file, validation split file
				Validation(const char*, const char*);
				//uint is the number of folds of validation
				void Validate(const uint);
};
