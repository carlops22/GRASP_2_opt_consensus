#include "GreedyRandomHeuristic.h"
#include "GreedyHeuristic.cpp"
#include <climits>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

GreedyRandomHeuristic :: GreedyRandomHeuristic(vector<string>& input, double& alpha )
 : greedy(input), alpha(alpha){
    input_strings=input;
    consensus_sequence="";
}
char GreedyRandomHeuristic :: getRandomCharacter() {
    static const char alphabet[] = "ATCG";
    return alphabet[rand() % (sizeof(alphabet) - 1)];
}
void GreedyRandomHeuristic :: greedyRandom(){
    int sequenceLength = input_strings[0].length();
    string bestMotif = input_strings[0];


    for (int i = 0; i < sequenceLength; ++i) {
        if (rand() / static_cast<double>(RAND_MAX) < alpha) { // numero random generado entre 0.0 y 1.0 < alpha
            // Caracter seleccionado al azar
            bestMotif[i] = getRandomCharacter();
        } else {
            char bestCharacter = bestMotif[i];
            int bestScore = greedy.get_heuristic_cost();

            for (char candidateChar : "ATCG") {
                int currentScore = 0;

                for (const string& candidate : input_strings) {
                    // Suma del cuadrado de las distancias para cierto carácter candidato
                    currentScore += greedy.hammingDistance_character(bestMotif, candidate, i, candidateChar);
                }

                if (currentScore < bestScore) {
                    bestScore = currentScore;
                    bestCharacter = candidateChar;
                    greedy.set_heuristic_cost(bestScore);
                }
            }

            bestMotif[i] = bestCharacter;
        }
    }
    if(greedy.get_heuristic_cost()== INT_MAX){ // en el caso de que todos los caracteres fueran elegidos al azar
        int heuristic_cost = greedy.sumSquaredHammingDistances(bestMotif,input_strings);
        greedy.set_heuristic_cost(heuristic_cost);
    }
    greedy.set_consensus_sequence(bestMotif);
};

void GreedyRandomHeuristic :: greedyRandomAlgorithm(){
    srand(static_cast<unsigned>(time(nullptr)));

    greedyRandom(); 
 
}

int GreedyRandomHeuristic :: getHeuristicCost(){
    return greedy.get_heuristic_cost();
}

string GreedyRandomHeuristic :: getConsensusSequence(){
    return greedy.get_consensus_sequence();
}