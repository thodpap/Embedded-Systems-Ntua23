import subprocess as sub

import logging

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger('dijkstra_logger')

names = ['sll', 'dll', 'dyn_arr']

for name in names:
    