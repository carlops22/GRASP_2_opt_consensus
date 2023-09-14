# greedy_2-optimality_consensus
A homework for 'Adaptive Systems', a greedy and random greedy implementation for a solution to the 2-optimality consensus 

# Method to run

If you want to just compile the Algorithms you can run the scripts listed below: 
## Compile programs:
### Windows (Powershell script)
`.\GreedyHeuristic_compile.ps1`

`.\GreedyRandomHeuristic_compile.ps1`
### Linux (bash script):
`chmod -x GreedyHeuristic_compile.sh`

`bash GreedyHeuristic_compile.sh`

`chmod -x GreedyRandomHeuristic_compile.sh`

`bash GreedyRandomHeuristic_compile.sh`
## Average and standard deviation results scripts:
### Windows (PowerShell):
`.\GreedyHeuristic_average_std.ps1`

`.\GreedyRandomHeuristic_average_std.ps1`

In case you want to run everything, the compiling and the dataset tests with the average and std results from the outputs wrote in a output file: results_random_greedy.csv

### Linux (bash script):
`chmod -x RunEverything.sh`

`bash RunEverything.sh`

# Plotting the results:

To plot the results obtained from the GreedyRandomHeuristic_average_std script, you can use my python program:

`python grafico_results_random_greedy.py`
or
`python3 grafico_results_random_greedy.py`
