#ifndef GREEDYHEURISTIC_H
#define GREEDYHEURISTIC_H
#include <vector>
#include <string>
using namespace std;

class GreedyHeuristic{
    private:
        vector<string> input_string;
        vector<int> distance_vector;
        int heuristic_cost;
    public:
        GreedyHeuristic(vector<string>);
        void calculate_cost();
        void first_distance(char);
        char closest_letter(vector<string>);
};

#endif