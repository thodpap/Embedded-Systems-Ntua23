'''

    FINDS THE BEST RESULT OF Bx, By AND PLOTS TOP 10

'''

def find_best_bx_by(file, plot_path):

    f = open(file, 'r')

    means = []
    bx_by = []
    maxs = []
    mins = []

    all_in_one = []

    for line in f:

        temp_bx = None
        temp_by = None
        temp_mean_time = None

        if "mean" in line:
            new_line = line.replace("\n", "").replace(" ", "")
            res = new_line.split("=")
            mean_time = float(res[1])
            mean_time = float("{:.6f}".format(mean_time))
            means.append(mean_time)

        if "for" in line:
            new_line = line.replace("\n", "").replace(" ", "")
            bx, by = new_line.split(",")
            bx = bx.split("=")[-1]
            by = by.split("=")[-1]
            bx_by.append((bx, by))

        if "max" in line:
            new_line = line.replace("\n", "").replace(" ", "")
            res = new_line.split("=")
            max_time = float(res[1])
            max_time = float("{:.6f}".format(max_time))
            maxs.append(max_time)

        if "min" in line:
            new_line = line.replace("\n", "").replace(" ", "")
            res = new_line.split("=")
            min_time = float(res[1])
            min_time = float("{:.6f}".format(min_time))
            mins.append(min_time)    

    for i in range(len(means)):
        all_in_one.append((means[i], maxs[i], mins[i], bx_by[i][0], bx_by[i][1]))

    all_in_one.sort()

    beautify_all_in_one = []

    for i in range(len(all_in_one)):
        beautify_all_in_one.append({"mean time": all_in_one[i][0],
                                    "max": all_in_one[i][1],
                                    "min": all_in_one[i][2],
                                    "bx": all_in_one[i][3],
                                    "by": all_in_one[i][4]
        })

    print(beautify_all_in_one)

    import matplotlib.pyplot as plt
    import random as ran
    import numpy as np
    import seaborn as sns
    import pandas as pd

    ten_first = all_in_one[:10]
    ran.shuffle(ten_first)

    ticks = []
    times = []
    versions = []
    total = None

    for i in range(len(ten_first)):
        ticks.append(f"bx = {ten_first[i][3]}, by = {ten_first[i][4]}")
        times.append(np.array([ten_first[i][0], ten_first[i][1], ten_first[i][2]]))
        versions.append(f"({ten_first[i][3]} {ten_first[i][4]})")

    total = np.vstack((times)).T

    print(total)

    print(total.shape, len(versions))

    df = pd.DataFrame(total)

    plt.figure(figsize=(9, 9))
    sns.set_theme(style="whitegrid")
    sns.boxplot(data=df)
    plt.ylabel("Mean Time (s)")
    plt.title('Top 10 (bx, by)')
    plt.xticks(range(len(versions)), versions, rotation = 45)

    plt.savefig(plot_path)

    return ([all_in_one[0][0], all_in_one[0][1], all_in_one[0][2]], all_in_one[0][3], all_in_one[0][4])


if __name__ == "__main__":

    find_best_bx_by("../results/results_phods_opt_bx_by.txt", "../plots/bx_by_top_10.png")