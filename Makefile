# Compiler
CXX = g++

CXXFLAGS = -std=c++11 -ggdb3 -Wall  

EXEC = raytrace.out

build: *.cpp *.h
	$(CXX) $(CXXFLAGS) $^ -o raytrace.out
