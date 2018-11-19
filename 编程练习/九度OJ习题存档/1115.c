#include<stdio.h>
int main()
{
    int a,b,i,ans;
    while(~scanf("%d",&a))
    {
        for(ans=0,i=0; i<5; ++i)
        {
            scanf("%d",&b);
            if(b<a) ans+=b;
        }
        printf("%d\n",ans);
    }
}
