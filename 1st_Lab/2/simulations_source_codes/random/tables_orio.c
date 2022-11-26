/*@ begin PerfTuning (
 def build {
  arg build_command = 'gcc -O0 -mcmodel=large';
 }
 def performance_counter {
  arg method = 'basic timer';
  arg repetitions = 10;
 }
 def performance_params {
  param UF[] = range(1,33);
 }

 def input_params {
  param N[] = [1000, 10000, 100000, 500000, 10000000, 100000000];
 }

 def input_vars {
  decl static double y[N] = random;
  decl double a1 = 0.5;
  decl double a2 = 1;
  decl double a3 = 1.5;
  decl static double x1[N] = random;
  decl static double x2[N] = random;
  decl static double x3[N] = random;
 }

 def search {
  arg algorithm = 'Randomsearch';
  arg time_limit = 15;
  arg total_runs = 13;
 }
) @*/

int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/

/*@ end @*/

/*@ end @*/

