import subprocess


# Here we suppose that time is printed
def run_code(code, executable, savefile):

    f = open(savefile, 'w')

    max_time = -1
    min_time = 1e9

    N = 10

    # Here we suppose that time is printed
    mean_time = 0 
    print(subprocess.run(['gcc', code, '-O0', '-o', executable], stdout=subprocess.PIPE).stdout.decode('utf-8'))
    for i in range(N):
        
        result = subprocess.run([executable], stdout=subprocess.PIPE)

        time = float(result.stdout.decode('utf-8').replace("\n", ""))

        f.write(f"{i} th loop execution time = {time}\n")
        max_time = max(time, max_time)

        min_time = min(time, min_time)

        mean_time += time
            
    mean_time /= N

    f.write("\n")

    f.write(f"mean time = {mean_time}\n")
    f.write(f"max time = {max_time}\n")
    f.write(f"min time = {min_time}\n")

    return [mean_time, max_time, min_time]

if __name__ == "__main__":

    # run_code('../code/tables_no_unroll.c', '../code/tables_no_unroll', '../results/results_no_unroll.txt')

    # run_code('../code/tables_exhaustive.c', '../code/tables_exhaustive', '../results/results_exhaustive_unroll.txt')

    # run_code('../code/tables_random.c', '../code/tables_random', '../results/results_random_unroll.txt')

    run_code('../code/tables_simplex.c', '../code/tables_simplex', '../results/results_simplex_unroll.txt')