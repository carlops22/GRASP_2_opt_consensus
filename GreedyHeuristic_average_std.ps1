
$fileNumbers = 0..99


$heuristicCosts = @()
$executionTimes = @()


foreach ($number in $fileNumbers) {
    $inputFileName = ".\dataset\inst_200_15_4_$number.txt"

    
    $output = & ".\GreedyHeuristic.exe" -i $inputFileName

    
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

# Resultados, como es deterministico no es necesario guardar en tabla para graficar
Write-Host "Average Heuristic Cost: $averageHeuristicCost"
Write-Host "Standard Deviation Heuristic Cost: $stdDevHeuristicCost"
Write-Host "Average Execution Time (milisegundos): $averageExecutionTime"
Write-Host "Standard Deviation Execution Time (milisegundos): $stdDevExecutionTime"