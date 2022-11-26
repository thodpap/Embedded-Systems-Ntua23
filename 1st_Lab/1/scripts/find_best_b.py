'''

    FINDS THE BEST RESULT OF B AND PLOTS THE RESULTS

'''

def find_best_b(file, plot_path):

    f = open(file, 'r')

    means = []
    b = []
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
            b_ = new_line.split("=")
            b.append(b_[1])

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
        all_in_one.append((means[i], maxs[i], mins[i], b[i]))

    all_in_one.sort()

    beautify_all_in_one = []

    for i in range(len(all_in_one)):
        beautify_all_in_one.append({"mean time": all_in_one[i][0],
                                    "max": all_in_one[i][1],
                                    "min": all_in_one[i][2],
                                    "b": all_in_one[i][3]
        })

    print(beautify_all_in_one)

    import matplotlib.pyplot as plt
    import random as ran
    import numpy as np

    plt.figure(figsize=(10, 10))
    
    test = all_in_one[::-1]

    ticks = []
    times = []
    for i in range(len(test)):
        ticks.append(f"b = {test[i][3]}")
        times.append(test[i][0])

    plt.plot(np.arange(len(test)), times)
    plt.xticks(range(len(ticks)), ticks, rotation = 45)
    plt.title("B plot")
    plt.ylabel("mean time")

    plt.savefig(plot_path)

    return ([all_in_one[0][0], all_in_one[0][1], all_in_one[0][2]], all_in_one[0][3])


if __name__ == "__main__":

    find_best_b("../results/results_phods_opt_best_b.txt", "../plots/betas.png")