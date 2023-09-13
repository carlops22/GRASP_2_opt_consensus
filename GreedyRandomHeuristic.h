#ifndef GREEDYRANDOMHEURISTIC_H
#define GREEDYRANDOMHEURISTIC_H
#include "GreedyHeuristic.h"
#include <vector>
#include <string>

class GreedyRandomHeuristic{
    private:
        std::vector<std::string> input_strings;
        std::string consensus_sequence;
        double alpha;
        GreedyHeuristic greedy;
    public:
        GreedyRandomHeuristic(std::vector<std::string>&, double&);
        char getRandomCharacter();
        void greedyRandom();
        void greedyRandomAlgorithm();
        int getHeuristicCost();
        std::string getConsensusSequence();
};






#endif