#ifndef GREEDYHEURISTIC_H
#define GREEDYHEURISTIC_H
#include <vector>
#include <string>


class GreedyHeuristic{
    private:
        std::vector<std::string> input_strings;
        int heuristic_cost;
        std::string consensus_sequence;
    public:
        GreedyHeuristic(std::vector<std::string>&);
        std::vector<std::string> get_input_strings();
        int hammingDistance(const std::string&, const std::string&);
        int hammingDistance_character(const std::string& , const std::string&, int, char);
        int sumSquaredHammingDistances(const std::string&, const std::vector<std::string>&) ;
        int get_heuristic_cost();
        void set_heuristic_cost(int&);
        std::string get_consensus_sequence();
        void set_consensus_sequence(std::string&);
        void find_consensus();
};

#endif