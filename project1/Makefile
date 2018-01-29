CXX = g++ -std=c++11
INCLUDES = ../Matrix/lib
CXXFLAGS = -g -Wall -I$(INCLUDES)
LIBS = $(INCLUDES)/lmatrix.a
SRC_FILES = $(wildcard *.cpp)
OBJ_FILES = $(patsubst %.cpp, %.o, $(SRC_FILES)) 
EXECUTABLES = $(patsubst %.cpp, %, $(SRC_FILES))

all: $(EXECUTABLES)

.PHONY: clean
clean:
	rm -f core $(EXECUTABLES) *.o

$(EXECUTABLES): $(OBJ_FILES)
		$(CXX)  -c $^

pr1: $(OBJ_FILES)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

