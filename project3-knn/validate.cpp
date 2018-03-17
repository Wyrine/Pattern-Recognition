#include "validate.hpp"
#include <cctype>

using namespace std;

Validation::Validation(const char* data, const char* grp)
{
		thread t1(&Validation::readGroupingFile, this, grp);
		//thread t2(&Validation::readAndBuildMatrix, this, data);
		t1.join(); //t2.join();
}
		void
Validation::Validate(const uint m)
{


}
		void
Validation::readGroupingFile(const char* grp)
{
		ifstream input(grp);
		if(! input.is_open() )
		{
				cerr << "Failed to open " << grp << ". Exiting.";
				exit(1);
		}
		char junk;
		vector<short> curLine;
		short curVal;
		do{
				do{
						input >> curVal;
						curLine.push_back(curVal);
				}while( isspace(input.peek()) );
				groups.push_back(curLine);
				curLine.clear();
		}while( input >> junk );
		input.close();
}
		void
Validation::readAndBuildMatrix(const char* data)
{


}
