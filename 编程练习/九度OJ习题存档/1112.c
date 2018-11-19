#include<stdio.h>
int main()
{
    int k;
    while(~scanf("%d",&k))
    {
        int a,i,ans=0,tmp=-1;
        for(i=0; i<k; ++i)
        {
            scanf("%d",&a);
            if(a<tmp) ++ans;
            tmp=a;
        }
        printf("%d\n",ans);
    }
}
