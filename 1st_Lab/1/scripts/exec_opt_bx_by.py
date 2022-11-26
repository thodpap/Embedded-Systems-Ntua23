import subprocess

def run_opt_bx_by(code, executable, savefile):

    print(subprocess.run(['gcc', code, '-O0', '-o', executable], stdout=subprocess.PIPE).stdout.decode('utf-8'))

    a_176 = [1, 2, 4, 8, 11, 16, 22, 44, 88, 176]
    a_144 = [1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 36, 48, 72, 144]

    N = 50

    total_min = -1
    total_max = 1e9
    total_mean = 1e9
    bx = None
    by = None    

    f = open(savefile, 'w')
    # Saves all results in the above file!
    for index, i in enumerate(a_144):

        for jindex, j in enumerate(a_176):

            f.write(f"for Bx = {i}, By = {j}")

            max_time = -1
            min_time = 1e9

            mean_time = 0 
            
            for _ in range(N):

                string = f" {i} {j}"

                result = subprocess.run([executable + string], stdout=subprocess.PIPE, shell=True)
                
                time = float(result.stdout.decode('utf-8').replace("\n", ""))
                
                max_time = max(max_time, time)

                min_time = min(min_time, time)

                mean_time += time

            mean_time /= N

            if mean_time < total_mean:
                total_mean = mean_time
                total_max = max_time
                total_min = min_time
                bx = a_144[index]
                by = a_176[jindex]

            f.write("\n")
            f.write(f"   mean time = {mean_time}\n")
            f.write(f"   max time = {max_time}\n")
            f.write(f"   min time = {min_time}\n")
            f.write("\n")

    f.close()

    return ([total_mean, total_max, total_min], bx, by)

if __name__ == "__main__":

    run_opt_bx_by('../code/phods_opt_bx_by.c', '../code/phods_opt_bx_by', "../results/results_phods_opt_bx_by.txt")