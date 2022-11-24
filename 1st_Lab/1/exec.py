import subprocess

print(subprocess.run(['gcc', 'phods_opt_bx_by.c', '-O0', '-o', 'phods_opt_bx_by'], stdout=subprocess.PIPE).stdout.decode('utf-8'))

a_176 = [1, 2, 4, 8, 11, 16, 22, 44, 88, 176]
a_144 = [1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 36, 48, 72, 144]

N = 50

f = open("results_phods_opt_bx_by.txt", 'w')

for i in a_144:

    for j in a_176:

        f.write(f"for Bx = {i}, By = {j}")

        max_time = -1
        min_time = 1e9

        mean_time = 0 
        c = 0
        
        for _ in range(N):

            string = f"{i} {j}"

            result = subprocess.run(['./phods_opt_bx_by ' + string], stdout=subprocess.PIPE, shell=True)
            
            time = float(result.stdout.decode('utf-8').replace("\n", ""))

        mean_time /= c

        f.write("\n")
        f.write(f"   mean time = {mean_time}\n")
        f.write(f"   max time = {max_time}\n")
        f.write(f"   min time = {min_time}\n")
        f.write("\n")

f.close()