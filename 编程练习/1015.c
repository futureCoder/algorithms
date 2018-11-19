#include<stdio.h>
int main()
{
    int a,b,k,mod=1;
    while(~scanf("%d%d%d",&a,&b,&k)&&(a||b))
    {
        for(mod=1; k; k--)
            mod*=10;
        if(a%mod==b%mod) printf("-1\n");
        else printf("%d\n",a+b);
    }
}
