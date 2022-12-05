import subprocess as sub

import logging

logging.basicConfig(level=logging.INFO)
logger = logging.getLogger('make_logger')

names = ['sll', 'dll', 'dyn_arr']
flags_cl = ['SLL_CL', 'DLL_CL', 'DYN_ARR_CL']
flags_pk = ['SLL_PK', 'DLL_PK', 'DYN_ARR_PK']

command = "gcc drr.c -o drr -pthread -no-pie  -lcdsl -L./../synch_implementations -I./../synch_implementations"

for index_i, i in enumerate(names):
    for index_j, j in enumerate(names):

        command = f"gcc drr.c -o drr_{i}_{j} -pthread -D{flags_cl[index_i]} -D{flags_pk[index_j]} -no-pie -lcdsl -L./../synch_implementations -I./../synch_implementations"
        logger.info("command:", command)
        logger.info(sub.run(command, stdout=sub.PIPE, shell=True).stdout.decode('utf-8'))

        logger.info(sub.run(f"mv drr_{i}_{j} D_binaries/", stdout=sub.PIPE, shell=True).stdout.decode('utf-8'))

