#!/bin/bash

#100 data sets
fileNumbers=({0..99})

#Arreglo de valores alpha

alphaValues=(0.05 0.1 0.15 0.2 0.25 0.3 0.35 0.4 0.45 0.5 0.55 0.6 0.65 0.7 0.75 0.8 0.85 0.9 0.95 1.0)
echo "Alpha,AverageHeuristicCost,StdDevHeuristicCost,AverageExecutionTime,StdDevExecutionTime" > results_random_greedy.csv

# LOOP para valores alpha
for alpha in "${alphaValues[@]}"; do
    heuristicCosts=()
    executionTimes=()

    # LOOP para cada archivo del dataset
    for number in "${fileNumbers[@]}"; do
        inputFileName="./dataset/inst_200_15_4_$number.txt"

        output=$("./GreedyRandomHeuristic.o" -i "$inputFileName" "$alpha")

        heuristicCost=$(echo "$output" | grep -oP "Heuristic cost: \K\d+")
        executionTime=$(echo "$output" | grep -oP "Tiempo de ejecucion: \K\d+(\.\d+)?")

        heuristicCosts+=("$heuristicCost")
        executionTimes+=("$executionTime")
    done

    # Calculo de media y STD
    sumHeuristicCost=0
    sumExecutionTime=0

    for cost in "${heuristicCosts[@]}"; do
        sumHeuristicCost=$(echo "scale=6; $sumHeuristicCost + $cost" | bc)
    done >/dev/null  

    for time in "${executionTimes[@]}"; do
        sumExecutionTime=$(echo "scale=6; $sumExecutionTime + $time" | bc)
    done >/dev/null  

    numFiles=${#fileNumbers[@]}
    averageHeuristicCost=$(echo "scale=6; $sumHeuristicCost / $numFiles" | bc)
    averageExecutionTime=$(echo "scale=6; $sumExecutionTime / $numFiles" | bc)

    stdDevHeuristicCost=0
    stdDevExecutionTime=0

    for cost in "${heuristicCosts[@]}"; do
        diffCost=$(echo "scale=6; $cost - $averageHeuristicCost" | bc)
        squaredDiffCost=$(echo "scale=6; $diffCost * $diffCost" | bc)
        stdDevHeuristicCost=$(echo "scale=6; $stdDevHeuristicCost + $squaredDiffCost" | bc)
    done >/dev/null  

    for time in "${executionTimes[@]}"; do
        diffTime=$(echo "scale=6; $time - $averageExecutionTime" | bc)
        squaredDiffTime=$(echo "scale=6; $diffTime * $diffTime" | bc)
        stdDevExecutionTime=$(echo "scale=6; $stdDevExecutionTime + $squaredDiffTime" | bc)
    done >/dev/null 

    stdDevHeuristicCost=$(echo "scale=6; sqrt($stdDevHeuristicCost / $numFiles)" | bc)
    stdDevExecutionTime=$(echo "scale=6; sqrt($stdDevExecutionTime / $numFiles)" | bc)

    # Guarda los resultados en una tabla csv para graficar a futuro
    echo "$alpha,$averageHeuristicCost,$stdDevHeuristicCost,$averageExecutionTime,$stdDevExecutionTime" >> results_random_greedy.csv
done