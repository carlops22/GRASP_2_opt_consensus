#include "GreedyRandomHeuristic.h"
#include <climits>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

GreedyRandomHeuristic :: GreedyRandomHeuristic(vector<string>& input, double& alpha, int& maxIterations )
 : greedy(input), alpha(alpha), maxIterations(maxIterations){
}

void GreedyRandomHeuristic :: greedyRandomStep(GreedyHeuristic& greedy, double alpha){
    int sequenceLength = greedy.get_input_strings()[0].length();
    string bestMotif = greedy.get_input_strings()[0];
    string currentMotif = bestMotif;

    for (int i = 0; i < sequenceLength; ++i) {
        if (rand() / static_cast<double>(RAND_MAX) < alpha) {
            // Randomly select a character
            currentMotif[i] = getRandomCharacter();
        } else {
            char bestCharacter = currentMotif[i];
            int bestScore = greedy.get_heuristic_cost();

            for (char candidateChar : "ATCG") {
                currentMotif[i] = candidateChar;
                int currentScore = greedy.sumSquaredHammingDistances(currentMotif, greedy.get_input_strings());

                if (currentScore < bestScore) {
                    bestScore = currentScore;
                    bestCharacter = candidateChar;
                }
            }

            currentMotif[i] = bestCharacter;
        }
    }
};

void GreedyRandomHeuristic :: greedyRandomAlgorithm(GreedyHeuristic& greedy, int maxIterations, double alpha){
    srand(static_cast<unsigned>(time(nullptr)));

    for (int i = 0; i < maxIterations; ++i) {
        greedyRandomStep(greedy, alpha);
    }    
}

int GreedyRandomHeuristic :: getHeuristicCost(){
    return greedy.get_heuristic_cost();
}

string GreedyRandomHeuristic :: getConsensusSequence(){
    return greedy.get_consensus_sequence();
}