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
	//still unsure about how to implement the key
	//int is the key, pair< Column vector of data, covariance matrix > 
	std::map<int, std::pair<Matrix, Matrix> > features;
	int totalElems;

public:
	Data();
//	Data(int key, int 
	int getTotal() const;
	Matrix getFeature(const int key) const;
	
};
