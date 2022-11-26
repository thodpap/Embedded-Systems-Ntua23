import subprocess

def run_opt(code, executable):
    
    max_time = -1
    min_time = 1e9

    N = 10

    # Here we suppose that time is printed
    mean_time = 0 
    print(subprocess.run(['gcc', code, '-O0', '-o', executable], stdout=subprocess.PIPE).stdout.decode('utf-8'))
    for i in range(N):
        
        print(i, "th loop")

        result = subprocess.run(executable + ' 16', stdout=subprocess.PIPE, shell=True)
        time = float(result.stdout.decode('utf-8').replace("\n", ""))

        # print("current time =", time)
        max_time = max(time, max_time)

        min_time = min(time, min_time)

        mean_time += time
            
    mean_time /= N

    print()

    print("mean time =", mean_time)
    print("max time =", max_time)
    print("min time =", min_time)

if __name__ == "__main__":

    run_opt('../code/phods_opt.c', '../code/phods_opt')