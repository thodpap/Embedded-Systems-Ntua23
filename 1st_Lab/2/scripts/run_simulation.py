import subprocess
import os

def run(workingDir, code):

    os.chdir(workingDir)

    print(subprocess.run(['sudo', 'orcc', code], stdout=subprocess.PIPE).stdout.decode('utf-8'))

    print("results are ready!")


if __name__ == "__main__":

    # run('../simulations_source_codes/exhaustive', 'tables_orio.c')
    
    # run('../simulations_source_codes/random', 'tables_orio.c')

    run('../simulations_source_codes/simplex', 'tables_orio.c')