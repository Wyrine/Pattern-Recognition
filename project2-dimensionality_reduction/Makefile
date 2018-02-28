CXX = g++ -std=c++11
INCLUDES = ../Matrix/include
CXXFLAGS = -g -Wall -I$(INCLUDES)
LIBS = $(INCLUDES)/libmatrix.a 
EXECUTABLES = driver
HEADERS = mat.hpp

all: $(EXECUTABLES)

.PHONY: clean
clean:
	rm -f core $(EXECUTABLES) *.o file

.SUFFIXES: .cpp .o
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $*.cpp

driver: mat.o driver.o $(HEADERS)
	$(CXX) -g -o driver mat.o driver.o $(LIBS)
