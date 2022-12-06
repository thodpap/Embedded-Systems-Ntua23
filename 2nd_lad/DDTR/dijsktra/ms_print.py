import subprocess as sub

files = sub.run("ls massif.out*", shell=True, stdout=sub.PIPE).stdout.decode('utf-8').split("\n")

files = files[:len(files) - 1]

for file in files:
    f = open(file, 'r')
    lines = f.readlines()
    for line in lines:
        if "cmd" in line:
            # print(line)
            name = line.replace("drr_", "").replace("\n", "").split(" ")[1]
            print(name)
            name = name.split("/")[2]
            print(name)
            f.close()

            # sub.run(f"touch ./mem_footprint_results/mem_footprint_log_{name}.txt", shell=True)
            sub.run(f"ms_print {file} > ./mem_footprint_results/mem_footprint_log_{name}.txt", shell=True)
            sub.run(f"mv {file} ./mem_footprint_results/", shell=True)

            break