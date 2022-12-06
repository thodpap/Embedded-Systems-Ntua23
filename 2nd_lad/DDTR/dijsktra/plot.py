import subprocess as sub

from_ = "./outputs_short_version/"
acc_ = "mem_accesses/"
foot_ = "mem_footprint/"

res_mem_accesses = []
res_mem_footprint = []
text = []

read_acc = sub.run(f"ls {from_ + acc_}", shell=True, stdout=sub.PIPE).stdout.decode('utf-8').split("\n")
read_acc = read_acc[:len(read_acc) -1]

read_foot = sub.run(f"ls {from_ + foot_}", shell=True, stdout=sub.PIPE).stdout.decode('utf-8').split("\n")
read_foot = read_foot[:len(read_foot) -1]

for file in read_acc:
    f = open(from_ + acc_ + file, 'r')
    text.append(file.replace("\n", "").replace(".txt", "").split("log_")[1])
    res_mem_accesses.append(float(f.readline().replace("\n", "").replace(" ", "").split(":")[1]))
    f.close()

for file in read_foot:
    f = open(from_ + foot_ + file, 'r')
    res_mem_footprint.append(float(f.readline().replace("\n", "").replace(" ", "").split(":")[1]))
    f.close()

import matplotlib.pyplot as plt

# for name in files_mem_accesses:
#     text.append(name.split("log_")[1].replace(".txt", ""))

plt.figure()

print(len(text), len(res_mem_accesses), len(res_mem_footprint))
print(text)

for i in range(len(text)):
    plt.annotate(text[i], (res_mem_accesses[i] + 10000000, res_mem_footprint[i]))

plt.scatter(res_mem_accesses, res_mem_footprint, color='blue')
plt.xlabel("Memory Acceses")
plt.ylabel("Memory Footprint (KB)")
plt.title("Comparison of different Data structures")
plt.xlim([0, 6*1e8])
plt.savefig("plots/mem_acc_mem_foot.png")