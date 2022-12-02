import subprocess as sub

import logging

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger('make_logger')

names = ['sll', 'dll', 'dyn_arr']

command = "gcc drr.c -o drr -pthread -no-pie  -lcdsl -L./../synch_implementations -I./../synch_implementations"

for i in names:
    for j in names:

        command = f"gcc drr_{i}_{j}.c -o drr_{i}_{j} -pthread -no-pie  -lcdsl -L./../synch_implementations -I./../synch_implementations"
        logger.info("command:", command)
        logger.info(sub.run(command, stdout=sub.PIPE, shell=True).stdout.decode('utf-8'))

        logger.info(sub.run(f"mv drr_{i}_{j} binaries/", stdout=sub.PIPE, shell=True).stdout.decode('utf-8'))

