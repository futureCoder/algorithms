#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        int count=0;
        while(n!=1)
        {
            if(n&1) n=(3*n+1)/2;
            else n/=2;
            ++count;
        }
        printf("%d\n",count);
    }
}
