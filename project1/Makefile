CXX = g++ -std=c++11
INCLUDES = ../Matrix/include
CXXFLAGS = -g -Wall -I$(INCLUDES)
LIBS = $(INCLUDES)/lmatrix.a 
EXECUTABLES = driver
HEADERS = mle.hpp

all: $(EXECUTABLES)

.PHONY: clean
clean:
	rm -f core $(EXECUTABLES) *.o

.SUFFIXES: .cpp .o
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $*.cpp

driver: driver.o mle.o mle.hpp
	$(CXX) $(CXXFLAGS) -g -o driver driver.o mle.o
