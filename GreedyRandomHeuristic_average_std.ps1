





# Set de 20 valores de alpha
$alphaValues = 0.05, 0.1, 0.15, 0.2, 0.25, 0.3, 0.35, 0.4, 0.45, 0.5, 0.55, 0.6, 0.65, 0.7, 0.75, 0.8, 0.85, 0.9, 0.95, 1.0
$results = @()
#loop for each alpha values
foreach ($alpha in $alphaValues) {
    $fileNumbers = 0..99
    $heuristicCosts = @()
    $executionTimes = @()
    #loop for 100 datasets

    foreach ($number in $fileNumbers) {
        $inputFileName = ".\dataset\inst_200_15_4_$number.txt"


        $output = & ".\GreedyRandomHeuristic.exe" -i $inputFileName $alpha

    
        $heuristicCost = [int]($output | Select-String "Heuristic cost: (\d+)" | ForEach-Object { $_.Matches.Groups[1].Value })
        $executionTime = [double]($output | Select-String "Tiempo de ejecucion: (\d+(\.\d+)?) milisegundos" | ForEach-Object { $_.Matches.Groups[1].Value })

        $heuristicCosts += $heuristicCost
        $executionTimes += $executionTime
    }



    # Calcular media y desviación estándar
    $averageHeuristicCost = ($heuristicCosts | Measure-Object -Average).Average
    $stdDevHeuristicCost = [Math]::Sqrt(($heuristicCosts | ForEach-Object { ($_ - $averageHeuristicCost) * ($_ - $averageHeuristicCost) } | Measure-Object -Average).Average)

    $averageExecutionTime = ($executionTimes | Measure-Object -Average).Average
    $stdDevExecutionTime = [Math]::Sqrt(($executionTimes | ForEach-Object { ($_ - $averageExecutionTime) * ($_ - $averageExecutionTime) } | Measure-Object -Average).Average)

    # Resultados
    Write-Host "Alpha = $alpha"
    Write-Host "Average Heuristic Cost: $averageHeuristicCost"
    Write-Host "Standard Deviation Heuristic Cost: $stdDevHeuristicCost"
    Write-Host "Average Execution Time (seconds): $($averageExecutionTime.ToString("F2"))"
    Write-Host "Standard Deviation Execution Time (seconds): $stdDevExecutionTime"
    $result = New-Object PSObject -property @{
        "Alpha" = $alpha
        "AverageHeuristicCost" = $averageHeuristicCost
        "StdDevHeuristicCost" = $stdDevHeuristicCost
        "AverageExecutionTime" = $averageExecutionTime
        "StdDevExecutionTime" = $stdDevExecutionTime
    }
    $results += $result
}
$results | Export-Csv -Path "results_random_greedy.csv" -Delimiter "`t" -NoTypeInformation