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
if ((N<=1000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [3.714e-06, 3.486e-06, 3.3e-06, 3.298e-06, 3.269e-06, 3.269e-06, 3.272e-06, 3.276e-06, 3.285e-06, 3.287e-06] 
Tuned for specific problem sizes: 
  N = 1000 
Best performance parameters: 
  UF = 1 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/
{
  for (int i = 0; i <= N - 1; i = i + 1) 
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
}
/*@ end @*/

} else if ((N<=10000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [3.9894e-05, 3.984e-05, 3.9176e-05, 3.9167e-05, 3.9238e-05, 3.93e-05, 3.9195e-05, 3.9224e-05, 3.9216e-05, 3.9261e-05] 
Tuned for specific problem sizes: 
  N = 10000 
Best performance parameters: 
  UF = 7 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/
{
  for (int i = 0; i <= N - 7; i = i + 7) {
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
    y[(i + 1)] = y[(i + 1)] + a1 * x1[(i + 1)] + a2 * x2[(i + 1)] + a3 * x3[(i + 1)];
    y[(i + 2)] = y[(i + 2)] + a1 * x1[(i + 2)] + a2 * x2[(i + 2)] + a3 * x3[(i + 2)];
    y[(i + 3)] = y[(i + 3)] + a1 * x1[(i + 3)] + a2 * x2[(i + 3)] + a3 * x3[(i + 3)];
    y[(i + 4)] = y[(i + 4)] + a1 * x1[(i + 4)] + a2 * x2[(i + 4)] + a3 * x3[(i + 4)];
    y[(i + 5)] = y[(i + 5)] + a1 * x1[(i + 5)] + a2 * x2[(i + 5)] + a3 * x3[(i + 5)];
    y[(i + 6)] = y[(i + 6)] + a1 * x1[(i + 6)] + a2 * x2[(i + 6)] + a3 * x3[(i + 6)];
  }
  for (int i = N - ((N - (0)) % 7); i <= N - 1; i = i + 1) 
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
}
/*@ end @*/

} else if ((N<=100000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [0.000459066, 0.000426349, 0.000418969, 0.000393128, 0.000394199, 0.000390252, 0.000389168, 0.00039307, 0.00039644, 0.000391586] 
Tuned for specific problem sizes: 
  N = 100000 
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

} else if ((N<=500000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [0.00241291, 0.00241808, 0.00230561, 0.0022731, 0.00241799, 0.00228934, 0.00244307, 0.0024318, 0.00230755, 0.00226962] 
Tuned for specific problem sizes: 
  N = 500000 
Best performance parameters: 
  UF = 28 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/
{
  for (int i = 0; i <= N - 28; i = i + 28) {
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
    y[(i + 13)] = y[(i + 13)] + a1 * x1[(i + 13)] + a2 * x2[(i + 13)] + a3 * x3[(i + 13)];
    y[(i + 14)] = y[(i + 14)] + a1 * x1[(i + 14)] + a2 * x2[(i + 14)] + a3 * x3[(i + 14)];
    y[(i + 15)] = y[(i + 15)] + a1 * x1[(i + 15)] + a2 * x2[(i + 15)] + a3 * x3[(i + 15)];
    y[(i + 16)] = y[(i + 16)] + a1 * x1[(i + 16)] + a2 * x2[(i + 16)] + a3 * x3[(i + 16)];
    y[(i + 17)] = y[(i + 17)] + a1 * x1[(i + 17)] + a2 * x2[(i + 17)] + a3 * x3[(i + 17)];
    y[(i + 18)] = y[(i + 18)] + a1 * x1[(i + 18)] + a2 * x2[(i + 18)] + a3 * x3[(i + 18)];
    y[(i + 19)] = y[(i + 19)] + a1 * x1[(i + 19)] + a2 * x2[(i + 19)] + a3 * x3[(i + 19)];
    y[(i + 20)] = y[(i + 20)] + a1 * x1[(i + 20)] + a2 * x2[(i + 20)] + a3 * x3[(i + 20)];
    y[(i + 21)] = y[(i + 21)] + a1 * x1[(i + 21)] + a2 * x2[(i + 21)] + a3 * x3[(i + 21)];
    y[(i + 22)] = y[(i + 22)] + a1 * x1[(i + 22)] + a2 * x2[(i + 22)] + a3 * x3[(i + 22)];
    y[(i + 23)] = y[(i + 23)] + a1 * x1[(i + 23)] + a2 * x2[(i + 23)] + a3 * x3[(i + 23)];
    y[(i + 24)] = y[(i + 24)] + a1 * x1[(i + 24)] + a2 * x2[(i + 24)] + a3 * x3[(i + 24)];
    y[(i + 25)] = y[(i + 25)] + a1 * x1[(i + 25)] + a2 * x2[(i + 25)] + a3 * x3[(i + 25)];
    y[(i + 26)] = y[(i + 26)] + a1 * x1[(i + 26)] + a2 * x2[(i + 26)] + a3 * x3[(i + 26)];
    y[(i + 27)] = y[(i + 27)] + a1 * x1[(i + 27)] + a2 * x2[(i + 27)] + a3 * x3[(i + 27)];
  }
  for (int i = N - ((N - (0)) % 28); i <= N - 1; i = i + 1) 
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
}
/*@ end @*/

} else if ((N<=10000000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [0.072433, 0.0709147, 0.0637828, 0.0581806, 0.0568562, 0.0649618, 0.0557967, 0.0551273, 0.0549993, 0.0598225] 
Tuned for specific problem sizes: 
  N = 10000000 
Best performance parameters: 
  UF = 32 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/
{
  for (int i = 0; i <= N - 32; i = i + 32) {
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
    y[(i + 13)] = y[(i + 13)] + a1 * x1[(i + 13)] + a2 * x2[(i + 13)] + a3 * x3[(i + 13)];
    y[(i + 14)] = y[(i + 14)] + a1 * x1[(i + 14)] + a2 * x2[(i + 14)] + a3 * x3[(i + 14)];
    y[(i + 15)] = y[(i + 15)] + a1 * x1[(i + 15)] + a2 * x2[(i + 15)] + a3 * x3[(i + 15)];
    y[(i + 16)] = y[(i + 16)] + a1 * x1[(i + 16)] + a2 * x2[(i + 16)] + a3 * x3[(i + 16)];
    y[(i + 17)] = y[(i + 17)] + a1 * x1[(i + 17)] + a2 * x2[(i + 17)] + a3 * x3[(i + 17)];
    y[(i + 18)] = y[(i + 18)] + a1 * x1[(i + 18)] + a2 * x2[(i + 18)] + a3 * x3[(i + 18)];
    y[(i + 19)] = y[(i + 19)] + a1 * x1[(i + 19)] + a2 * x2[(i + 19)] + a3 * x3[(i + 19)];
    y[(i + 20)] = y[(i + 20)] + a1 * x1[(i + 20)] + a2 * x2[(i + 20)] + a3 * x3[(i + 20)];
    y[(i + 21)] = y[(i + 21)] + a1 * x1[(i + 21)] + a2 * x2[(i + 21)] + a3 * x3[(i + 21)];
    y[(i + 22)] = y[(i + 22)] + a1 * x1[(i + 22)] + a2 * x2[(i + 22)] + a3 * x3[(i + 22)];
    y[(i + 23)] = y[(i + 23)] + a1 * x1[(i + 23)] + a2 * x2[(i + 23)] + a3 * x3[(i + 23)];
    y[(i + 24)] = y[(i + 24)] + a1 * x1[(i + 24)] + a2 * x2[(i + 24)] + a3 * x3[(i + 24)];
    y[(i + 25)] = y[(i + 25)] + a1 * x1[(i + 25)] + a2 * x2[(i + 25)] + a3 * x3[(i + 25)];
    y[(i + 26)] = y[(i + 26)] + a1 * x1[(i + 26)] + a2 * x2[(i + 26)] + a3 * x3[(i + 26)];
    y[(i + 27)] = y[(i + 27)] + a1 * x1[(i + 27)] + a2 * x2[(i + 27)] + a3 * x3[(i + 27)];
    y[(i + 28)] = y[(i + 28)] + a1 * x1[(i + 28)] + a2 * x2[(i + 28)] + a3 * x3[(i + 28)];
    y[(i + 29)] = y[(i + 29)] + a1 * x1[(i + 29)] + a2 * x2[(i + 29)] + a3 * x3[(i + 29)];
    y[(i + 30)] = y[(i + 30)] + a1 * x1[(i + 30)] + a2 * x2[(i + 30)] + a3 * x3[(i + 30)];
    y[(i + 31)] = y[(i + 31)] + a1 * x1[(i + 31)] + a2 * x2[(i + 31)] + a3 * x3[(i + 31)];
  }
  for (int i = N - ((N - (0)) % 32); i <= N - 1; i = i + 1) 
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
}
/*@ end @*/

} else if ((N<=100000000)) {

/**-- (Generated by Orio) 
Best performance cost: 
  [0.5361, 0.53108, 0.537813, 0.544037, 0.513915, 0.530596, 0.520959, 0.510822, 0.539441, 0.538459] 
Tuned for specific problem sizes: 
  N = 100000000 
Best performance parameters: 
  UF = 17 
--**/


int i;

/*@ begin Loop ( 
    transform Unroll(ufactor=UF) 
    for (i=0; i<=N-1; i++)
      y[i] = y[i] + a1*x1[i] + a2*x2[i] + a3*x3[i];
) @*/
{
  for (int i = 0; i <= N - 17; i = i + 17) {
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
    y[(i + 13)] = y[(i + 13)] + a1 * x1[(i + 13)] + a2 * x2[(i + 13)] + a3 * x3[(i + 13)];
    y[(i + 14)] = y[(i + 14)] + a1 * x1[(i + 14)] + a2 * x2[(i + 14)] + a3 * x3[(i + 14)];
    y[(i + 15)] = y[(i + 15)] + a1 * x1[(i + 15)] + a2 * x2[(i + 15)] + a3 * x3[(i + 15)];
    y[(i + 16)] = y[(i + 16)] + a1 * x1[(i + 16)] + a2 * x2[(i + 16)] + a3 * x3[(i + 16)];
  }
  for (int i = N - ((N - (0)) % 17); i <= N - 1; i = i + 1) 
    y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
}
/*@ end @*/

}
/*@ end @*/

