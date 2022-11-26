from scripts.find_initial import find_initial

from scripts.find_best_b import find_best_b 

from scripts.find_best_bx_by import find_best_bx_by

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

initial_res = find_initial('./results/results_initial.txt')

opt_b_res, b = find_best_b('./results/results_phods_opt_best_b.txt', './plots/betas.png')

opt_bx_by_res, bx, by = find_best_bx_by('./results/results_phods_opt_bx_by.txt', './plots/bx_by_top_10.png')

initial_res = np.array(initial_res)

opt_b_res = np.array(opt_b_res)

opt_bx_by_res = np.array(opt_bx_by_res)

print("initial time")
print(initial_res)
print()

print("optimal b =", b, "time")
print(opt_b_res)
print()

print("optimal bx =", bx, "by =", by, "time")
print(opt_bx_by_res)


total = np.vstack((initial_res, opt_b_res, opt_bx_by_res))

column_wise = total.transpose()

print("results in colums:")
print(column_wise)

versions = ['Initial', f'Opt B = {b}', f'Opt Bx = {bx}, By = {by}']
sns.set_theme(style="whitegrid")

df = pd.DataFrame(column_wise)
df.columns = versions

plt.figure()
sns.boxplot(data=df)
plt.ylabel("Mean Time (s)")
plt.title('Box Plot for Mean times of each implementation')
plt.savefig("./plots/best_times.png", bbox_inches="tight")


better_resolution = np.vstack((opt_b_res, opt_bx_by_res))
better_resolution_column_wise = better_resolution.transpose()

better_resolution_versions = [f'Opt B = {b}', f'Opt Bx = {bx}, By = {by}'] # 'Initial' has been removed for visual clarity
sns.set_theme(style="whitegrid")

better_resolution_df = pd.DataFrame(better_resolution_column_wise) # time 1 has been removed from the list
better_resolution_df.columns = better_resolution_versions

plt.figure()
sns.boxplot(data=better_resolution_df)
plt.ylabel("Mean Time (s)")
plt.title('Box Plot for Mean times of Optimized only implementaitons (better resolution)')
plt.savefig("./plots/best_times_better_resolution.png", bbox_inches="tight")