import subprocess as sub
import logging

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger('mem_acesses_logger')

names = ['sll', 'dll', 'dyn_arr']

total = len(names) * len(names)
counter = 1

for i in names:
    for j in names:

        sub.run(f"touch /mem_accesses_results/\"mem_accesses_log_{i}_{j}.txt", shell=True, stdout=sub.PIPE).stdout.decode('utf-8')

        command = f"valgrind --log-file=./mem_accesses_results/\"mem_accesses_log_{i}_{j}.txt\" --tool=lackey --trace-mem=yes ./binaries/drr_{i}_{j}"

        logger.info(sub.run(command, shell=True, stdout=sub.PIPE).stdout.decode('utf-8'))

        logger.info(str(counter) + " done out of " + str(total))
        counter += 1