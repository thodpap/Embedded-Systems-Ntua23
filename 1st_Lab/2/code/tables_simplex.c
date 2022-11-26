#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

int main()
{
    int i;
    int N = 100000000;
    double *x1, *x2, *x3, *y;
    double a1 = 0.5;
    double a2 = 1;
    double a3 = 1.5;

    x1 = (double *)malloc(N * sizeof(double));
    x2 = (double *)malloc(N * sizeof(double));
    x3 = (double *)malloc(N * sizeof(double));
    y = (double *)malloc(N * sizeof(double));

    // Do not modify this loop
    for (i = 0; i <= N - 1; i++)
    {
        x1[i] = (double)i * 0.5;
        x1[i] = (double)i * 0.4;
        x2[i] = (double)i * 0.8;
        x3[i] = (double)i * 0.2;
        y[i] = 0;
    }

    /*
    Τhis is the basic loop of tables.c. Isolate it in file tables_orio.c,
    in which all the parameters for Design Space Exploration (DSE) and loop
    transfornations should be defined.
    */

    

    if ((N <= 1000))
    {

        //  UF = 2

        int i;

        struct timeval start, end;

        gettimeofday(&start, NULL);

        {
            for (int i = 0; i <= N - 2; i = i + 2)
            {
                y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
                y[(i + 1)] = y[(i + 1)] + a1 * x1[(i + 1)] + a2 * x2[(i + 1)] + a3 * x3[(i + 1)];
            }
            for (int i = N - ((N - (0)) % 2); i <= N - 1; i = i + 1)
                y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
        }

        gettimeofday(&end, NULL);

        float time = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) * 0.000001;

        printf("%f", time);

    }

    else if ((N <= 10000))
    {

        //  UF = 5

        int i;

        struct timeval start, end;

        gettimeofday(&start, NULL);

        {
            for (int i = 0; i <= N - 5; i = i + 5)
            {
                y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
                y[(i + 1)] = y[(i + 1)] + a1 * x1[(i + 1)] + a2 * x2[(i + 1)] + a3 * x3[(i + 1)];
                y[(i + 2)] = y[(i + 2)] + a1 * x1[(i + 2)] + a2 * x2[(i + 2)] + a3 * x3[(i + 2)];
                y[(i + 3)] = y[(i + 3)] + a1 * x1[(i + 3)] + a2 * x2[(i + 3)] + a3 * x3[(i + 3)];
                y[(i + 4)] = y[(i + 4)] + a1 * x1[(i + 4)] + a2 * x2[(i + 4)] + a3 * x3[(i + 4)];
            }
            for (int i = N - ((N - (0)) % 5); i <= N - 1; i = i + 1)
                y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
        }

        gettimeofday(&end, NULL);

        float time = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) * 0.000001;

        printf("%f", time);

    }

    else if ((N <= 100000))
    {

        //  UF = 4

        int i;

        struct timeval start, end;

        gettimeofday(&start, NULL);

        {
            for (int i = 0; i <= N - 4; i = i + 4)
            {
                y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
                y[(i + 1)] = y[(i + 1)] + a1 * x1[(i + 1)] + a2 * x2[(i + 1)] + a3 * x3[(i + 1)];
                y[(i + 2)] = y[(i + 2)] + a1 * x1[(i + 2)] + a2 * x2[(i + 2)] + a3 * x3[(i + 2)];
                y[(i + 3)] = y[(i + 3)] + a1 * x1[(i + 3)] + a2 * x2[(i + 3)] + a3 * x3[(i + 3)];
            }
            for (int i = N - ((N - (0)) % 4); i <= N - 1; i = i + 1)
                y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
        }

        gettimeofday(&end, NULL);

        float time = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) * 0.000001;

        printf("%f", time);

    }

    else if ((N <= 500000))
    {

        //  UF = 18

        int i;

        struct timeval start, end;

        gettimeofday(&start, NULL);

        {
            for (int i = 0; i <= N - 18; i = i + 18)
            {
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
            }
            for (int i = N - ((N - (0)) % 18); i <= N - 1; i = i + 1)
                y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
        }

        gettimeofday(&end, NULL);

        float time = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) * 0.000001;

        printf("%f", time);

    }

    else if ((N <= 10000000))
    {

        //  UF = 26

        int i;

        struct timeval start, end;

        gettimeofday(&start, NULL);

        {
            for (int i = 0; i <= N - 26; i = i + 26)
            {
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
            }
            for (int i = N - ((N - (0)) % 26); i <= N - 1; i = i + 1)
                y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
        }

        gettimeofday(&end, NULL);

        float time = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) * 0.000001;

        printf("%f", time);

    }

    else
    {

        //  UF = 22

        int i;

        struct timeval start, end;

        gettimeofday(&start, NULL);

        {
            for (int i = 0; i <= N - 22; i = i + 22)
            {
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
            }
            for (int i = N - ((N - (0)) % 22); i <= N - 1; i = i + 1)
                y[i] = y[i] + a1 * x1[i] + a2 * x2[i] + a3 * x3[i];
        }

        gettimeofday(&end, NULL);

        float time = end.tv_sec - start.tv_sec + (end.tv_usec - start.tv_usec) * 0.000001;

        printf("%f", time);

    }

    

    return 0;
}