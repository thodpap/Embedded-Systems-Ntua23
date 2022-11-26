from scripts.run import run_code

run_code('../code/tables_no_unroll.c', '../code/tables_no_unroll', '../results/results_no_unroll.txt')
run_code('../code/tables_exhaustive.c', '../code/tables_exhaustive', '../results/results_exhaustive_unroll.txt')
run_code('../code/tables_random.c', '../code/tables_random', '../results/results_random_unroll.txt')
run_code('../code/tables_simplex.c', '../code/tables_simplex', '../results/results_simplex_unroll.txt')