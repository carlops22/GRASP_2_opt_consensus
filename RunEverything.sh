#!/bin/bash

# List of scripts to run
scripts=(
    "GreedyHeuristic_compile.sh"
    "GreedyRandomHeuristic_compile.sh"
    "GreedyHeuristic_average_std.sh"
    "GreedyRandomHeuristic_average_std.sh"		
)

# Loop through the list and execute each script
for script in "${scripts[@]}"; do
    if [ -f "$script" ]; then
        echo "Running $script..."
        bash "$script"
        echo "Finished $script."
    else
        echo "Script file '$script' not found."
    fi
done