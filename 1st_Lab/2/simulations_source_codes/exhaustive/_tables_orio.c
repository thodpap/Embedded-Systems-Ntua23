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
  arg algorithm = 'Exhaustive';
 }
) @*/
if ((N<=1000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [3.951e-06, 3.595e-06, 3.338e-06, 3.345e-06, 3.379e-06, 3.307e-06, 3.332e-06, 3.362e-06, 3.329e-06, 3.337e-06] 
Tuned for specific problem sizes: 
  N = 1000 
Best performance parameters: 
  UF = 2 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/
{
  for (int i = 0; i <= N - 2; i = i + 2) {
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
    y[(i + 1)] = y[(i + 1)] + a1 * x1[(i + 1)] + a2 * x2[(i + 1)] + a3 * x3[(i + 1)];
  }
  for (int i = N - ((N - (0)) % 2); i <= N - 1; i = i + 1) 
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
}
/*@ end @*/

} else if ((N<=10000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [6.295e-05, 3.799e-05, 3.7322e-05, 3.7281e-05, 3.7272e-05, 3.7532e-05, 3.7584e-05, 3.7329e-05, 3.7318e-05, 3.7392e-05] 
Tuned for specific problem sizes: 
  N = 10000 
Best performance parameters: 
  UF = 4 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/
{
  for (int i = 0; i <= N - 4; i = i + 4) {
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
    y[(i + 1)] = y[(i + 1)] + a1 * x1[(i + 1)] + a2 * x2[(i + 1)] + a3 * x3[(i + 1)];
    y[(i + 2)] = y[(i + 2)] + a1 * x1[(i + 2)] + a2 * x2[(i + 2)] + a3 * x3[(i + 2)];
    y[(i + 3)] = y[(i + 3)] + a1 * x1[(i + 3)] + a2 * x2[(i + 3)] + a3 * x3[(i + 3)];
  }
  for (int i = N - ((N - (0)) % 4); i <= N - 1; i = i + 1) 
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
}
/*@ end @*/

} else if ((N<=100000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [0.000425912, 0.000419531, 0.000390707, 0.000386647, 0.000384845, 0.000385433, 0.000397305, 0.000386168, 0.000388284, 0.00039746] 
Tuned for specific problem sizes: 
  N = 100000 
Best performance parameters: 
  UF = 10 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/
{
  for (int i = 0; i <= N - 10; i = i + 10) {
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
    y[(i + 1)] = y[(i + 1)] + a1 * x1[(i + 1)] + a2 * x2[(i + 1)] + a3 * x3[(i + 1)];
    y[(i + 2)] = y[(i + 2)] + a1 * x1[(i + 2)] + a2 * x2[(i + 2)] + a3 * x3[(i + 2)];
    y[(i + 3)] = y[(i + 3)] + a1 * x1[(i + 3)] + a2 * x2[(i + 3)] + a3 * x3[(i + 3)];
    y[(i + 4)] = y[(i + 4)] + a1 * x1[(i + 4)] + a2 * x2[(i + 4)] + a3 * x3[(i + 4)];
    y[(i + 5)] = y[(i + 5)] + a1 * x1[(i + 5)] + a2 * x2[(i + 5)] + a3 * x3[(i + 5)];
    y[(i + 6)] = y[(i + 6)] + a1 * x1[(i + 6)] + a2 * x2[(i + 6)] + a3 * x3[(i + 6)];
    y[(i + 7)] = y[(i + 7)] + a1 * x1[(i + 7)] + a2 * x2[(i + 7)] + a3 * x3[(i + 7)];
    y[(i + 8)] = y[(i + 8)] + a1 * x1[(i + 8)] + a2 * x2[(i + 8)] + a3 * x3[(i + 8)];
    y[(i + 9)] = y[(i + 9)] + a1 * x1[(i + 9)] + a2 * x2[(i + 9)] + a3 * x3[(i + 9)];
  }
  for (int i = N - ((N - (0)) % 10); i <= N - 1; i = i + 1) 
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
}
/*@ end @*/

} else if ((N<=500000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [0.00278221, 0.0022827, 0.00228531, 0.00223872, 0.00229432, 0.0023435, 0.00225556, 0.00244318, 0.0023187, 0.00231051] 
Tuned for specific problem sizes: 
  N = 500000 
Best performance parameters: 
  UF = 13 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/
{
  for (int i = 0; i <= N - 13; i = i + 13) {
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
    y[(i + 1)] = y[(i + 1)] + a1 * x1[(i + 1)] + a2 * x2[(i + 1)] + a3 * x3[(i + 1)];
    y[(i + 2)] = y[(i + 2)] + a1 * x1[(i + 2)] + a2 * x2[(i + 2)] + a3 * x3[(i + 2)];
    y[(i + 3)] = y[(i + 3)] + a1 * x1[(i + 3)] + a2 * x2[(i + 3)] + a3 * x3[(i + 3)];
    y[(i + 4)] = y[(i + 4)] + a1 * x1[(i + 4)] + a2 * x2[(i + 4)] + a3 * x3[(i + 4)];
    y[(i + 5)] = y[(i + 5)] + a1 * x1[(i + 5)] + a2 * x2[(i + 5)] + a3 * x3[(i + 5)];
    y[(i + 6)] = y[(i + 6)] + a1 * x1[(i + 6)] + a2 * x2[(i + 6)] + a3 * x3[(i + 6)];
    y[(i + 7)] = y[(i + 7)] + a1 * x1[(i + 7)] + a2 * x2[(i + 7)] + a3 * x3[(i + 7)];
    y[(i + 8)] = y[(i + 8)] + a1 * x1[(i + 8)] + a2 * x2[(i + 8)] + a3 * x3[(i + 8)];
    y[(i + 9)] = y[(i + 9)] + a1 * x1[(i + 9)] + a2 * x2[(i + 9)] + a3 * x3[(i + 9)];
    y[(i + 10)] = y[(i + 10)] + a1 * x1[(i + 10)] + a2 * x2[(i + 10)] + a3 * x3[(i + 10)];
    y[(i + 11)] = y[(i + 11)] + a1 * x1[(i + 11)] + a2 * x2[(i + 11)] + a3 * x3[(i + 11)];
    y[(i + 12)] = y[(i + 12)] + a1 * x1[(i + 12)] + a2 * x2[(i + 12)] + a3 * x3[(i + 12)];
  }
  for (int i = N - ((N - (0)) % 13); i <= N - 1; i = i + 1) 
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
}
/*@ end @*/

} else if ((N<=10000000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [0.0520089, 0.0531725, 0.0531104, 0.0540033, 0.0581885, 0.0545741, 0.0552447, 0.0532953, 0.0534711, 0.0534617] 
Tuned for specific problem sizes: 
  N = 10000000 
Best performance parameters: 
  UF = 9 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/
{
  for (int i = 0; i <= N - 9; i = i + 9) {
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
    y[(i + 1)] = y[(i + 1)] + a1 * x1[(i + 1)] + a2 * x2[(i + 1)] + a3 * x3[(i + 1)];
    y[(i + 2)] = y[(i + 2)] + a1 * x1[(i + 2)] + a2 * x2[(i + 2)] + a3 * x3[(i + 2)];
    y[(i + 3)] = y[(i + 3)] + a1 * x1[(i + 3)] + a2 * x2[(i + 3)] + a3 * x3[(i + 3)];
    y[(i + 4)] = y[(i + 4)] + a1 * x1[(i + 4)] + a2 * x2[(i + 4)] + a3 * x3[(i + 4)];
    y[(i + 5)] = y[(i + 5)] + a1 * x1[(i + 5)] + a2 * x2[(i + 5)] + a3 * x3[(i + 5)];
    y[(i + 6)] = y[(i + 6)] + a1 * x1[(i + 6)] + a2 * x2[(i + 6)] + a3 * x3[(i + 6)];
    y[(i + 7)] = y[(i + 7)] + a1 * x1[(i + 7)] + a2 * x2[(i + 7)] + a3 * x3[(i + 7)];
    y[(i + 8)] = y[(i + 8)] + a1 * x1[(i + 8)] + a2 * x2[(i + 8)] + a3 * x3[(i + 8)];
  }
  for (int i = N - ((N - (0)) % 9); i <= N - 1; i = i + 1) 
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
}
/*@ end @*/

} else if ((N<=100000000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [0.473523, 0.472862, 0.479144, 0.481707, 0.47269, 0.46991, 0.475565, 0.47689, 0.499889, 0.485071] 
Tuned for specific problem sizes: 
  N = 100000000 
Best performance parameters: 
  UF = 9 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/
{
  for (int i = 0; i <= N - 9; i = i + 9) {
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
    y[(i + 1)] = y[(i + 1)] + a1 * x1[(i + 1)] + a2 * x2[(i + 1)] + a3 * x3[(i + 1)];
    y[(i + 2)] = y[(i + 2)] + a1 * x1[(i + 2)] + a2 * x2[(i + 2)] + a3 * x3[(i + 2)];
    y[(i + 3)] = y[(i + 3)] + a1 * x1[(i + 3)] + a2 * x2[(i + 3)] + a3 * x3[(i + 3)];
    y[(i + 4)] = y[(i + 4)] + a1 * x1[(i + 4)] + a2 * x2[(i + 4)] + a3 * x3[(i + 4)];
    y[(i + 5)] = y[(i + 5)] + a1 * x1[(i + 5)] + a2 * x2[(i + 5)] + a3 * x3[(i + 5)];
    y[(i + 6)] = y[(i + 6)] + a1 * x1[(i + 6)] + a2 * x2[(i + 6)] + a3 * x3[(i + 6)];
    y[(i + 7)] = y[(i + 7)] + a1 * x1[(i + 7)] + a2 * x2[(i + 7)] + a3 * x3[(i + 7)];
    y[(i + 8)] = y[(i + 8)] + a1 * x1[(i + 8)] + a2 * x2[(i + 8)] + a3 * x3[(i + 8)];
  }
  for (int i = N - ((N - (0)) % 9); i <= N - 1; i = i + 1) 
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
}
/*@ end @*/

}
/*@ end @*/

