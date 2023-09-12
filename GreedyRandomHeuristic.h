#ifndef GREEDYRANDOMHEURISTIC_H
#define GREEDYRANDOMHEURISTIC_H
#include "GreedyHeuristic.h"
#include <vector>
#include <string>

class GreedyRandomHeuristic{
    private:
        std::vector<std::string> input_strings;
        int heuristic_cost;
        std::string consensus_sequence;
        double alpha;
        int maxIterations;
        GreedyHeuristic greedy;
    public:
        GreedyRandomHeuristic(std::vector<std::string>&, double&, int&);
        char getRandomCharacter();
        void greedyRandomStep(GreedyHeuristic&, double);
        void greedyRandomAlgorithm(GreedyHeuristic&, int, double);
        int getHeuristicCost();
        string getConsensusSequence();
};






#endif