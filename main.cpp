#include "GreedyHeuristic.cpp"
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

std::vector<std::vector<int>> read_file(std::istream& input)
{
    std::vector<std::vector<int>> lines;

    std::string line;
    while (std::getline(input, line))
    {
        std::istringstream line_stream(line);

        lines.emplace_back(std::istream_iterator<int>(line_stream),
                           std::istream_iterator<int>());
    }

    return lines;
}

int main(int argc, char** argv){

}