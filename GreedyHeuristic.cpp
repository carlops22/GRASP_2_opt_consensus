#include "GreedyHeuristic.h"
#include <numeric>
#include<map>


GreedyHeuristic::GreedyHeuristic(vector<string> input){
    input_string=input;
    heuristic_cost=-1;

};

void GreedyHeuristic::calculate_cost(){
    if(heuristic_cost !=-1){
        
        heuristic_cost= accumulate(distance_vector.begin(),distance_vector.end(),0);
        
    }
    
};
int single_distance(char a, char b){
    
}

void GreedyHeuristic:: first_distance(char mostRepeatedLetter){
                
}

char closest_letter(vector<string> input_string){
    std::map<char, int> letterFrequency;

    // Iterate through the vector of strings
    for (const std::string& str : input_string) {
        if (!str.empty()) {
            char firstLetter = str[0]; // Get the first letter of the string
            letterFrequency[firstLetter]++; // Increment the frequency count
        }
    }

    char mostRepeatedLetter = '\0'; // Initialize with a null character
    int maxFrequency = 0;

    // Find the most repeated letter
    for (const auto& pair : letterFrequency) {
        if (pair.second > maxFrequency) {
            maxFrequency = pair.second;
            mostRepeatedLetter = pair.first;
        }
    }

    return mostRepeatedLetter;
}

