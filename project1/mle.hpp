#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <cstdlib>
#include <string>
#include <Matrix.h>
#include <fstream>
#include "mle.hpp"

class Data
{	
	//this idea is to be scrapped. I will make an array of a new object
	/*
		Things needed to be stored:

		variance
		covariance matrix for feature
		mean
		data
		count for the field
	*/

	//int is the key, pair< Column vector of data, covariance matrix > 
	std::map<int, std::pair<Matrix, Matrix> > features;
	int totalElems;

public:
	Data();
	int getTotal() const;
	Matrix getFeature(const int key) const;
	
};
