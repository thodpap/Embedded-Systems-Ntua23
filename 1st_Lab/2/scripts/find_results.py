'''

    FINDS THE RESULTS OF EACH IMPLEMENTATION

'''

def find_results(file):

    f = open(file, 'r')

    mean = 0
    max_ = 0
    min_ = 0

    all_in_one = []

    for line in f:

        if "mean" in line:
            new_line = line.replace("\n", "").replace(" ", "")
            res = new_line.split("=")
            mean = float(res[1])
            mean = float("{:.6f}".format(mean))

        if "max" in line:
            new_line = line.replace("\n", "").replace(" ", "")
            res = new_line.split("=")
            max_ = float(res[1])
            max_ = float("{:.6f}".format(max_))

        if "min" in line:
            new_line = line.replace("\n", "").replace(" ", "")
            res = new_line.split("=")
            min_ = float(res[1])
            min_ = float("{:.6f}".format(min_))    


    return [mean, max_, min_]