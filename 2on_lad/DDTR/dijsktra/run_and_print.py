import subprocess as sub

import logging

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger('dijkstra_logger')

names = ['dijkstra', 'dijkstra_dynamic_sll', 'dijkstra_dynamic_dll', 'dijkstra_dynamic_dyn_arr']
outs = ['dijkstra.txt', 'dijkstra_dynamic_sll.txt', 'dijkstra_dynamic_dll.txt', 'dijkstra_dynamic_dyn_arr.txt']
for i, name in enumerate(names):
    sub.run(f"touch ./correctness/{outs[i]}", shell=True, stdout=sub.PIPE).stdout.decode('utf-8')

    logger.info(sub.run(f"./binaries/{name} input.dat ./correctness/{outs}", shell=True, stdout=sub.PIPE).stdout.decode('utf-8'))
