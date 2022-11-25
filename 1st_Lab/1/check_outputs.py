import subprocess

print(subprocess.run(['gcc', 'phods_opt.c', '-O0', '-o', 'phods_opt'], stdout=subprocess.PIPE).stdout.decode('utf-8'))

a_176 = [1, 2, 4, 8, 11, 16, 22, 44, 88, 176]
a_144 = [1, 2, 3, 4, 6, 8, 9, 12, 16, 18, 24, 36, 48, 72, 144]

N = 50

f = open("my_results.txt", 'w')

max_time = -1
min_time = 1e9

mean_time = 0 

result = subprocess.run('./phods_opt', stdout=subprocess.PIPE, shell=True)

res = result.stdout.decode('utf-8')
   
f.write(res)

f.close()