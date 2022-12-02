import subprocess

def run_initial(code, executable, savefile):

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

    run_initial('../code/phods.c', '../code/phods', '../results/results_initial.txt')
