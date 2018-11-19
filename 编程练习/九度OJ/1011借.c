#include <stdio.h>
#include <stdlib.h>
int max(int a,int b)
{
    return (a>=b)?a:b;
}
int main()
{
    freopen("in.txt","r",stdin);
    int i,j,k,first,last;
    while(scanf("%d",&k)!=EOF&&k!=0)
    {
        int *array = (int *)malloc(sizeof(int)*k);
        int *sum = (int *)malloc(sizeof(int)*k);
        for(i=0; i<k; i++)
        {
            scanf("%d",array+i);
            if(i==0)
            {
                sum[i]=array[i];
                last=i;
            }
            else
            {
                sum[i]=max(sum[i-1]+array[i],array[i]);
                if(sum[i]>sum[last])
                    last=i;
            }
        }
        if(sum[last]<0)
        {
            first=0;
            last=k-1;
            sum[last]=0;
        }
        else
        {
            first=last;
            while(sum[first]!=array[first])
                first--;
        }
        printf("%d %d %d\n",sum[last],array[first],array[last]);
        free(array);
        free(sum);
    }
    return 0;
}
