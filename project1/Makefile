CXX = g++ -std=c++11
INCLUDES = ../Matrix/lib
CXXFLAGS = -g -Wall -I$(INCLUDES)
LIBS = $(INCLUDES)/lmatrix.a
EXECUTABLES = mle
HEADERS = mle.hpp

all: $(EXECUTABLES)

.PHONY: clean
clean:
	rm -f core $(EXECUTABLES) *.o

.SUFFIXES: .cpp .o
.cpp.o:
	$(CXX) $(CXXFLAGS) -c $*.cpp

mle: mle.o mle.hpp
	$(CXX) $(CXXFLAGS) -g -o mle mle.o
