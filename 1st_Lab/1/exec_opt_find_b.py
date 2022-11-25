import subprocess

print(subprocess.run(['gcc', 'phods_opt.c', '-O0', '-o', 'phods_opt'], stdout=subprocess.PIPE).stdout.decode('utf-8'))

cds = [1, 2, 4, 8, 16]


N = 10

f = open("results_phods_opt_best_b.txt", 'w')

for i in cds:

    f.write(f"for B = {i}")

    max_time = -1
    min_time = 1e9

    mean_time = 0 
    
    for _ in range(N):

        result = subprocess.run(['./phods_opt ' + str(i)], stdout=subprocess.PIPE, shell=True)
        
        time = float(result.stdout.decode('utf-8').replace("\n", ""))
        
        max_time = max(max_time, time)

        min_time = min(min_time, time)

        mean_time += time

    mean_time /= N

    f.write("\n")
    f.write(f"   mean time = {mean_time}\n")
    f.write(f"   max time = {max_time}\n")
    f.write(f"   min time = {min_time}\n")
    f.write("\n")

f.close()