import subprocess

max_time = -1
min_time = 1e9

N = 10

mean_time = 0 
print(subprocess.run(['gcc', 'phods_opt.c', '-O0', '-o', 'phods_opt'], stdout=subprocess.PIPE).stdout.decode('utf-8'))
for i in range(N):
    
    print(i, "th loop")

    result = subprocess.run(['./phods_opt'], stdout=subprocess.PIPE)
    time = int(result.stdout.decode('utf-8').replace("\n", ""))

    print("current time =", time)

    max_time = max(time, max_time)
    min_time = min(time, min_time)
    mean_time += time

mean_time /= N

print()

print("mean time =", mean_time)
print("max time =", max_time)
print("min time =", min_time)