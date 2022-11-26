import subprocess

def run_opt_b(code, executable, savefile):

    print(subprocess.run(['gcc', code, '-O0', '-o', executable], stdout=subprocess.PIPE).stdout.decode('utf-8'))

    cds = [1, 2, 4, 8, 16]

    total_mean = 1e9
    total_max = 1e9
    total_min  = -1
    total_b = None

    N = 10

    f = open(savefile, 'w')

    for index, i in enumerate(cds):

        f.write(f"for B = {i}")

        max_time = -1
        min_time = 1e9

        mean_time = 0 
        
        for _ in range(N):

            result = subprocess.run([executable + " " + str(i)], stdout=subprocess.PIPE, shell=True)
            
            time = float(result.stdout.decode('utf-8').replace("\n", ""))
            
            max_time = max(max_time, time)

            min_time = min(min_time, time)

            mean_time += time

        mean_time /= N
        
        if mean_time < total_mean:
            total_mean = mean_time
            total_max = max_time
            total_min = min_time
            total_b = cds[index]

        f.write("\n")
        f.write(f"   mean time = {mean_time}\n")
        f.write(f"   max time = {max_time}\n")
        f.write(f"   min time = {min_time}\n")
        f.write("\n")

    f.close()

    return ([total_mean, total_max, total_min], total_b)

if __name__ =="__main__":

    run_opt_b('../code/phods_opt.c', '../code/phods_opt', "../results/results_phods_opt_best_b.txt")