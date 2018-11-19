#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        int count=0;
        for(; n!=1; ++count)
            if(n&1) n=(3*n+1)/2;
            else n>>=1;
        printf("%d\n",count);
    }
}
