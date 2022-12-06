import subprocess as sub

write_ = "./outputs_short_version"

mem_acceses = []
text = []

files_mem_accesses = sub.run("ls mem_accesses_results", shell=True, stdout=sub.PIPE).stdout.decode('utf-8').split("\n")
files_mem_accesses = files_mem_accesses[:len(files_mem_accesses) - 1]
res_mem_accesses = []

to_ = "/mem_accesses/"
for file in files_mem_accesses:
    filename = write_ + to_ + file
    text.append(file.replace(".txt", "").split("log_")[1])
    print(filename, file)
    res = int(sub.run(f"cat mem_accesses_results/{file} | grep 'I\| L' | wc -l", shell=True, stdout=sub.PIPE).stdout.decode('utf-8').replace("\n", ""))
    res_mem_accesses.append(res)
    sub.run(f"touch {filename}", shell=True)
    f = open(filename, 'w')
    f.write("memory accesses: " + str(res))
    f.close()

mem_footprint = []

files_mem_footprint = sub.run("ls mem_footprint_results", shell=True, stdout=sub.PIPE).stdout.decode('utf-8').split("\n")
print(files_mem_footprint)
files_mem_footprint = files_mem_footprint[:len(files_mem_footprint) - 1]
res_mem_footprint = []

to_ = "/mem_footprint/"
for file in files_mem_footprint:
    if "mem_" not in file:
        continue
    filename = write_ + to_ + file
    print(filename, file)
    sub.run(f"touch {filename}", shell=True)
    f = open(f"mem_footprint_results/{file}", 'r')
    f_write = open(filename, 'w')
    lines = f.readlines()

    factor = 1

    for line in lines:

        if 'MB' in line:
            factor = 1000

        if '^' in line:
            res = float(line.split('^')[0]) * factor
            print(res)
            res_mem_footprint.append(res)
            f_write.write(f"memory footprint: {str(res)}")
            break
    f.close()
    # res_mem_footprint.append(int(sub.run(f"cat {file} | grep 'I\| L' | wc -l", shell=True, stdout=sub.PIPE).stdout.decode('utf-8').replace("\n", "")))