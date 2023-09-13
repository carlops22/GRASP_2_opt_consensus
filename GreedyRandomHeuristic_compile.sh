#!/bin/bash


CXX=g++


CXXFLAGS="-std=c++11"

# Source file 
SOURCE_FILE="main_greedy_random_heuristic.cpp"

# Output binary name 
OUTPUT_BINARY="GreedyRandomHeuristic.o"

# Compile the program with GreedyHeuristic and GreedyRandomHeuristic
$CXX $CXXFLAGS -o $OUTPUT_BINARY $SOURCE_FILE

echo "Compilation for Greedy Random Heuristic completed."