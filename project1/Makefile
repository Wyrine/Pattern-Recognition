CXX = g++ -std=c++11
INCLUDES = ../Matrix/include
CXXFLAGS = -g -Wall -I$(INCLUDES)
LIBS = $(INCLUDES)/libmatrix.a 
EXECUTABLES = driver
HEADERS = mat.hpp

all: $(EXECUTABLES)

.PHONY: clean
clean:
	rm -f core $(EXECUTABLES) *.o

.SUFFIXES: .cpp .o
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $*.cpp

driver: driver.o mat.o mat.hpp
	$(CXX) -g -o driver driver.o mat.o $(LIBS)
