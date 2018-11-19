#include<stdio.h>
int main()
{
    int a,b,k,i,mod,ans;
    while(~scanf("%d%d%d",&a,&b,&k)&&(a||b))
    {
        for(mod=10,i=1; i<k; ++i)
            mod*=10;
        a%=mod;
        b%=mod;
        if(a==b) printf("-1\n");
        else printf("%d\n",a+b);
    }
}
