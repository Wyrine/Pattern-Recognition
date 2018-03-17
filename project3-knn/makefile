CXX = g++ -std=c++11
INCLUDES = ../Matrix/include
CXXFLAGS = -O2 -g -Wall -I$(INCLUDES)
LIBS = $(INCLUDES)/libmatrix.a 
EXECUTABLES = driver
HEADERS = mat.hpp validate.hpp
RESULT = performance

all: $(EXECUTABLES)

.PHONY: clean
clean:
		@rm -f core $(EXECUTABLES) *.o *.txt
		@rm -rf $(RESULT)

.SUFFIXES: .cpp .o
.cpp.o:
		$(CXX) $(CXXFLAGS) -c $*.cpp

driver: validate.o mat.o driver.o $(HEADERS)
		@$(CXX) -g -o driver mat.o validate.o driver.o $(LIBS)
		@mkdir $(RESULT)
