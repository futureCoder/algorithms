#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i,f=1;
        for(i=0; i<n; ++i)
            f*=10;
        for(i=1; i<f; ++i)
            printf("%d\n",i);
    }
}
