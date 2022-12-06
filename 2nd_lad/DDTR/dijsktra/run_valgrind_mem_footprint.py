import subprocess as sub
import logging

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger('mem_acesses_logger')

names = ['sll', 'dll', 'dyn_arr']
binaries = ['dijkstra_dynamic_sll', 'dijkstra_dynamic_dll', 'dijkstra_dynamic_dyn_arr']
# outs = ['dijkstra_dynamic_sll.txt', 'dijkstra_dynamic_dll.txt', 'dijkstra_dynamic_dyn_arr.txt']

total = len(names)
counter = 1

for i, name in enumerate(names):
    
    # sub.run(f"touch /mem_footprint_results/mem_footprint_log_{name}.txt", shell=True, stdout=sub.PIPE).stdout.decode('utf-8')

    command = f"valgrind --tool=massif ./binaries/{binaries[i]} input.dat"
    print(command)
    logger.info(sub.run(command, shell=True, stdout=sub.PIPE).stdout.decode('utf-8'))

    logger.info(str(counter) + " done out of " + str(total))
    counter += 1