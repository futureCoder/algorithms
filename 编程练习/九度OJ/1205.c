#include<stdio.h>
#define N 90
typedef long long lld;
lld ans[N];
int main()
{
    int i,k;
    memset(ans,0,sizeof(ans));
    ans[0]=ans[1]=1;
    for(i=2; i<N; ++i)
        ans[i]=ans[i-1]+ans[i-2];
    while(~scanf("%d",&k))
        printf("%d\n",ans[k]);
}
