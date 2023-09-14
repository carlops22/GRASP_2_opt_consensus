import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_csv('results_random_greedy.csv')
print(df.columns)
alpha= df['Alpha']
average_heuristic_cost = df['AverageHeuristicCost']
average_execution_time = df['AverageExecutionTime']

fig, axes = plt.subplots(nrows=2, ncols=1, figsize=(8,6))

axes[0].plot(alpha, average_heuristic_cost, marker='o', linestyle='-')
axes[0].set_title('Average Heuristic Cost vs Alpha')
axes[0].set_xlabel('Alpha')
axes[0].set_ylabel('Average Heuristic Cost')

axes[1].plot(alpha, average_execution_time, marker='o', linestyle='-')
axes[1].set_title('Average Execution Time vs Alpha')
axes[1].set_xlabel('Alpha')
axes[1].set_ylabel('Average Execution Time (milliseconds)')

plt.tight_layout()

plt.savefig('average_results_random_greedy.png')

plt.show()