CXX=g++
NUMPY=/usr/share/pyshared/numpy/core/include/numpy
EIGEN=/home/kkastner/src/ProcessMusic/
#NUMPY=/usr/lib/pymodules/python2.7/numpy/core/include/numpy/
CXXFLAGS=-Ofast -Wall -std=c++0x -march=native -I$(NUMPY) -I$(EIGEN)
LIBS=-lmpg123 -lfftw3 -ldl -lpython2.7 -lsndfile -lconfig++

EXEC=main
OBJECTS=\
	main.o \
        Configurator.o \
	DataCollector.o \
	MuBlock.o \
	Process.o \
	PythonAnalyzer.o 

all: main

.PHONY: clean

clean:
	rm *.o main 

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LIBS)

MuBlock.o: MuBlock.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

DataCollector.o: DataCollector.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Process.o: Process.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<	

PythonAnalyzer.o: PythonAnalyzer.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<	

Configurator.o: Configurator.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<	
