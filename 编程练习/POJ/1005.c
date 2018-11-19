#include<stdio.h>
#include<math.h>
#define dist(x,y) (x*x+y*y)
#define PI 3.1415926535898
int main()
{
    freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n))
    {
        int i,year;
        float x,y;
        for(i=0; i<n; ++i)
        {
            scanf("%f %f",&x,&y);
            year=(int )dist(x,y)*PI/100 + 1;
            printf("Property %d: This property will begin eroding in year %d.\n",i+1,year);
        }
        printf("END OF OUTPUT.\n");
    }
}
