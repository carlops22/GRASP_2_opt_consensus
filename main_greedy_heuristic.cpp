#include "GreedyHeuristic.cpp"
#include "LoadInputData.cpp"
#include <chrono>
#include <iostream>
#include <cstdlib>


using namespace std;


int main(int argc, char* argv[]) {
    if (argc != 3 || string(argv[1]) != "-i") {
        cerr << "Usar: " << argv[0] << " -i <instancia-problema>" << endl;
        return 1;
    }
    string inputFileName = argv[2];

    std::vector<std::string> input_data = loadInputData(inputFileName);
    GreedyHeuristic greedy(input_data);


    auto start_time = std::chrono::high_resolution_clock::now();

    greedy.find_consensus();

    auto end_time = std::chrono::high_resolution_clock::now();
    double execution_time = std::chrono::duration<double>(end_time - start_time).count();

    cout <<"Heuristic cost: " << greedy.get_heuristic_cost() <<endl;
    cout << "Tiempo usado: " << execution_time << " segundos" << endl;

    return 0;
}

