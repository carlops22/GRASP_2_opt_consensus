#include "GreedyRandomHeuristic.cpp"
#include "LoadInputData.cpp"
#include <cstdlib>
#include <iostream>
int main(int argc, char* argv[]) {
    if (argc != 4 || string(argv[1]) != "-i") {
        cerr << "Usage: " << argv[0] << " -i <instancia-problema> <alpha>" << endl;
        return 1;
    }

    string inputFileName = argv[2];
    double alpha = stod(argv[3]);

    // Load input data from the specified file
    vector<string> input_data = loadInputData(inputFileName);
    

    GreedyRandomHeuristic greedy_random(input_data,alpha);

    auto start_time = chrono::high_resolution_clock::now();

    greedy_random.greedyRandomAlgorithm();

    auto end_time = chrono::high_resolution_clock::now();
    double execution_time = chrono::duration<double>(end_time - start_time).count();


    cout << "Heuristic cost: " << greedy_random.getHeuristicCost() << endl;
    cout << "Tiempo de ejecucion: " << execution_time*1000 << " milisegundos" << endl;
    return 0;
}
