#!/bin/bash


CXX=g++


CXXFLAGS="-std=c++11"

# Source file (main.cpp)
SOURCE_FILE="main_greedy_heuristic.cpp"

# Output binary name (your_program_name)
OUTPUT_BINARY="GreedyHeuristic.o"

# Compile the program with GreedyHeuristic and GreedyRandomHeuristic
$CXX $CXXFLAGS -o $OUTPUT_BINARY $SOURCE_FILE

echo "Compilation for Greedy Heuristic completed."