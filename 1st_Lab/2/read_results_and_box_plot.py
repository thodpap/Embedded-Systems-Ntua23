from scripts.find_results import find_results

unrolls = ["No unroll", "exhaustive, UF = 9", "random, UF = 17", "simplex, UF = 22"]

no_unroll = find_results('./results/results_no_unroll.txt')
exhaustive = find_results('./results/results_exhaustive_unroll.txt')
random = find_results('./results/results_random_unroll.txt')
simplex = find_results('./results/results_simplex_unroll.txt')

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

print("no unroll results")
print(no_unroll)

print("exhaustive results, UF = 9")
print(exhaustive)

print("random results, UF = 17")
print(random)

print("simplex results, UF = 22")
print(simplex)

total = np.vstack((no_unroll, exhaustive, random, simplex)).T

sns.set_theme(style="whitegrid")

df = pd.DataFrame(total)
df.columns = unrolls

plt.figure(figsize=(10, 10))
sns.boxplot(data=df)
plt.ylabel("Time (s)")
plt.title('Box Plot for Times of each implementation')
plt.savefig("./plots/times.png", bbox_inches="tight")