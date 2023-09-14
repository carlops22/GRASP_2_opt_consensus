#!/bin/bash


for number in {0..99}
do
    
    inputFileName="./dataset/inst_200_15_4_$number.txt"

    output=$(./GreedyHeuristic.o -i "$inputFileName")

    #Grep los valores entregados en output para el script
    heuristicCost=$(echo "$output" | grep -oP "Heuristic cost: \K\d+")
    executionTime=$(echo "$output" | grep -oP "Tiempo de ejecucion: \K\d+(\.\d+)?")

    heuristicCosts+=("$heuristicCost")
    executionTimes+=("$executionTime")
done


totalHeuristicCost=0

for cost in "${heuristicCosts[@]}"
do
    totalHeuristicCost=$((totalHeuristicCost + cost))
done

averageHeuristicCost=$(bc -l <<< "scale=2; $totalHeuristicCost / ${#heuristicCosts[@]}")
stdDevHeuristicCost=0

for cost in "${heuristicCosts[@]}"
do
    stdDevHeuristicCost=$(bc -l <<< "$stdDevHeuristicCost + ($cost - $averageHeuristicCost) ^ 2")
done

stdDevHeuristicCost=$(bc -l <<< "scale=2; sqrt($stdDevHeuristicCost / ${#heuristicCosts[@]})")
totalExecutionTime=0

for time in "${executionTimes[@]}"
do
    totalExecutionTime=$(bc -l <<< "$totalExecutionTime + $time")
done

averageExecutionTime=$(bc -l <<< "scale=2; $totalExecutionTime / ${#executionTimes[@]}")
stdDevExecutionTime=0

for time in "${executionTimes[@]}"
do
    stdDevExecutionTime=$(bc -l <<< "$stdDevExecutionTime + ($time - $averageExecutionTime) ^ 2")
done

stdDevExecutionTime=$(bc -l <<< "scale=2; sqrt($stdDevExecutionTime / ${#executionTimes[@]})")

# Resultados, como es deterministico no es necesario una tabla para graficar
echo "Average Heuristic Cost: $averageHeuristicCost"
echo "Standard Deviation Heuristic Cost: $stdDevHeuristicCost"
echo "Average Execution Time (milliseconds): $averageExecutionTime"
echo "Standard Deviation Execution Time (milliseconds): $stdDevExecutionTime"