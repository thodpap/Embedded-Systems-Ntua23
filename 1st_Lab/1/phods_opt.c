/*Parallel Hierarchical One-Dimensional Search for motion estimation*/
/*Initial algorithm - Used for simulation and profiling             */

#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#define N 144     /*Frame dimension for QCIF format*/
#define M 176     /*Frame dimension for QCIF format*/
#define B 16      /*Block size*/
#define p 7       /*Search space. Restricted in a [-p,p] region around the
                    original location of the block.*/

void read_sequence(int current[N][M], int previous[N][M])
{ 
	FILE *picture0, *picture1;
	int i, j;

	if((picture0=fopen("akiyo0.y","rb")) == NULL)
	{
		printf("Previous frame doesn't exist.\n");
		exit(-1);
	}

	if((picture1=fopen("akiyo1.y","rb")) == NULL) 
	{
		printf("Current frame doesn't exist.\n");
		exit(-1);
	}

  /*Input for the previous frame*/
  for(i=0; i<N; i++)
  {
    for(j=0; j<M; j++)
    {
      previous[i][j] = fgetc(picture0);
    }
  }

	/*Input for the current frame*/
	for(i=0; i<N; i++)
  {
		for(j=0; j<M; j++)
    {
			current[i][j] = fgetc(picture1);
    }
  }

	fclose(picture0);
	fclose(picture1);
}


void phods_motion_estimation(int current[N][M], int previous[N][M],
    int vectors_x[N/B][M/B],int vectors_y[N/B][M/B])
{
    int x, y, i, j, k, l, p1, p2, q2, distx, disty, S, min1, min2, bestx, besty;

    distx = 0;
    disty = 0;

    long int b_b = 255*B*B;

    /*For all blocks in the current frame*/

    int x_bound = N/B;
    int y_bound = M/B;

    for(x=0; x < x_bound; x++)
    {

        for(y=0; y < y_bound; y++)
        {

            S = 4;

            vectors_x[x][y] = 0;
            vectors_y[x][y] = 0;

            int vec_x = vectors_x[x][y];
            int vec_y = vectors_y[x][y];

            int b_x = B*x;
            int b_y = B*y;

            int b_vec_x = b_x + vec_x;
            int b_vec_y = b_y + vec_y;

            
            while(S > 0)
            {

                min1 = b_b;
                min2 = b_b;

                /*For all candidate blocks in X dimension*/
                for(i=-S; i<S+1; i+=S)     
                {

                    distx = 0;
                    disty = 0;

                    int M_1 = M-1;
                    int N_1 = N-1;
                    int M_1_i = (M-1) - i;

                    /*For all pixels in the block*/
                    for(k=0; k<B; k++)     
                    {

                        int b_x_k = b_x + k;
                        int b_x_vec_x = b_vec_x + k;
                        int b_x_vec_x_i = b_x_vec_x + i;
                        int8_t check_x_i = (b_x_vec_x_i) < 0 || (b_x_vec_x_i) > N_1;
                        int8_t check_x = (b_x_vec_x) < 0 || (b_x_vec_x) > N_1;

                        for(l=0; l<B; l++)
                        {
                            
                            int b_y_l = b_y + l;

                            p1 = current[b_x_k][b_y_l];

                            int b_y_vec_y = b_vec_y + l;

                            p2 = ((check_x_i) || (b_y_vec_y) < 0 || (b_y_vec_y) > M_1) ? 0 : previous[b_x_vec_x_i][b_y_vec_y];

                            distx += abs(p1-p2);

                            q2 = ((check_x) || (b_y_vec_y) < - i || (b_y_vec_y) > M_1_i) ? 0 : previous[b_x_vec_x][b_y_vec_y + i];

                            disty += abs(p1-q2);

                        }
                        
                    }

                    if(distx < min1)
                    {
                        min1 = distx;
                        bestx = i;
                    }

                    if(disty < min2)
                    {
                        min2 = disty;
                        besty = i;
                    }

                    
                }
                
                S = S/2;
                vectors_x[x][y] += bestx;
                vectors_y[x][y] += besty;

            }
        }
    }
} 

int main()
{  
  int current[N][M], previous[N][M], motion_vectors_x[N/B][M/B],
      motion_vectors_y[N/B][M/B], i, j;

	read_sequence(current,previous);

  struct timeval start, end;

  gettimeofday(&start, NULL);

  phods_motion_estimation(current,previous,motion_vectors_x,motion_vectors_y);

  gettimeofday(&end, NULL);

  printf("%ld\n", end.tv_usec - start.tv_usec);

  return 0;
}
