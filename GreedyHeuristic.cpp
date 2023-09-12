#include "GreedyHeuristic.h"
#include <numeric>
#include<climits>
#include <iostream>
using namespace std;

GreedyHeuristic::GreedyHeuristic(vector<string>& input){
    input_strings=input; 
    heuristic_cost=-1;
    consensus_sequence="";
};
int GreedyHeuristic :: get_heuristic_cost(){
    return heuristic_cost;
};
void GreedyHeuristic :: set_heuristic_cost(int& heuristic_cost){
    this->heuristic_cost=heuristic_cost;
}
string GreedyHeuristic :: get_consensus_sequence(){
    return consensus_sequence;
};
void GreedyHeuristic :: set_consensus_sequence(string& consensus_sequence){
    this-> consensus_sequence = consensus_sequence;
}
int GreedyHeuristic:: hammingDistance(const string& seq1, const string& seq2){
    int distance = 0;
    for (size_t i = 0; i < seq1.length(); ++i) {
        if (seq1[i] != seq2[i]) {
            distance++;
        }
    }
    return distance*distance;
};
int GreedyHeuristic::hammingDistance_character(const string& seq1, const string& seq2, int position, char candidateChar) {
    int distance = 0;
    for (size_t i = 0; i < seq1.length(); ++i) {
        char char1 = (i == position) ? candidateChar : seq1[i];
        char char2 = seq2[i];
        
        if (char1 != char2) {
            distance++;
        }
    }
    return distance * distance; // Square the Hamming distance
};
int GreedyHeuristic :: sumSquaredHammingDistances(const string& motif, const vector<string>& candidates) {
    int sumDistanceSquared = 0;

    for (const string& candidate : candidates) {
        int distance = hammingDistance(motif, candidate);
        sumDistanceSquared += distance;
    }

    return sumDistanceSquared;
};
void GreedyHeuristic::find_consensus() {
    int sequenceLength = input_strings[0].length();
    string bestMotif = input_strings[0]; 

    for (int i = 0; i < sequenceLength; ++i) {
        char bestCharacter = input_strings[0][i];
        int bestScore = INT_MAX;

        for (char candidateChar : "ATCG") {
            int currentScore = 0;

            for (const string& candidate : input_strings) {
                // Suma del cuadrado de las distancias para cierto carácter
                currentScore += hammingDistance_character(bestMotif, candidate, i, candidateChar);
            }

            if (currentScore < bestScore) {
                bestScore = currentScore;
                bestCharacter = candidateChar;
            }
        }

        bestMotif[i] = bestCharacter;
    }
    //costo total de la secuencia armada
    heuristic_cost = sumSquaredHammingDistances(bestMotif, input_strings);
    consensus_sequence = bestMotif;
};


