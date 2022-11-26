from scripts.exec_initial import run_initial

from scripts.exec_opt_b import run_opt_b

from scripts.exec_opt_bx_by import run_opt_bx_by

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import seaborn as sns

initial_res = run_initial('./code/phods.c', './code/phods', './results/results_inital.txt')

opt_b_res, b = run_opt_b('./code/phods_opt.c', './code/phods_opt', "./results/results_phods_opt_best_b.txt")

opt_bx_by_res, bx, by = run_opt_bx_by('./code/phods_opt_bx_by.c', './code/phods_opt_bx_by', "./results/results_phods_opt_bx_by.txt")

initial_res = np.array(initial_res).reshape((3,1))

opt_b_res = np.array(opt_b_res).reshape((3,1))

opt_bx_by_res = np.array(opt_bx_by_res).reshape((3,1))

print("initial time")
print(initial_res)
print()

print("optimal b =", b, "time")
print(opt_b_res)
print()

print("optimal bx =", bx, "by =", by, "time")
print(opt_bx_by_res)



# total = np.stack((initial_res, opt_b_res, opt_bx_by_res), axis=-1)

# print()
# print(total)
# print(total.shape)
# np.reshape(total, (3,3))
# print(total.shape)

# df = pd.DataFrame(total, columns=['initial', 'optimized, b = ' + str(b), 'optimized bx = ' + str(bx) + ' by = ' + str(by)])


# sns.boxplot(data=df)
# plt.ylabel("Time (s)")
# plt.savefig("./plots/best_times.png", bbox_inches="tight")