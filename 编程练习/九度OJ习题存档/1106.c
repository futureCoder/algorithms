#include<stdio.h>
int cvt(int n)
{
    int ret=0;
    do
    {
        ret+=(n%10);
        n/=10;
    }
    while(n!=0);
    return ret;
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        printf("%d %d\n",cvt(n),cvt(n*n));
    }
}
