#include<stdio.h>
#include<stdlib.h>
typedef struct herb
{
    int time;
    int value;
} herb;
int cmp(const void *a,const void *b)
{
    herb c=*(herb *)a;
    herb d=*(herb *)b;
    return d.value-c.value;
}
int main()
{
    int t,m;
    while(~scanf("%d%d",&t,&m))
    {
        int i,ans=0;
        herb h[m];
        for(i=0; i<m; ++i)
        {
            scanf("%d%d",&h[i].time,&h[i].value);
        }
        qsort(h,m,sizeof(herb),cmp);
        for(i=0; i<m; ++i)
        {
            if(t<h[i].time) continue;
            else
            {
                ans+=h[i].value;
                t-=h[i].time;
            }
        }
        printf("%d\n",ans);
    }
}
