#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "math.h"
#define N  500000000
int main()
{

 double s,x,y;
 unsigned num, j;
 srand((unsigned) time(NULL));
 num=0;
 for( j = 0;j < N;j++)
 {
  x=(double)rand()/(RAND_MAX);
  y = (double)rand()/RAND_MAX;
  x=x*12-2;
  y=y*300;
     if(y<3*x*x)
   num++;
 }
 s=((double)num/N)*(12*300);
 printf("%lf\n",s);
 return 0;
}
