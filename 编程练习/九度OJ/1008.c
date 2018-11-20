#include<stdio.h>
#include<memory.h>
#include<limits.h>
typedef struct node
{
    int len;
    int cost;
} node;
int main()
{
    freopen("in.txt","r",stdin);
    int n,m;
    while(~scanf("%d%d",&n,&m)&&(n||m))
    {
        int i,j,a,b,c,d,s,t,k,tmp,min,flag[n+1];
        node g[n+1][n+1];
        node ans[n+1];
        memset(g,INT_MAX,sizeof(g));
        for(i=0; i<=m; ++i)
        {
            ans[i].len=ans[i].cost=INT_MAX;
            flag[i]=0;
        }
        for(i=0; i<m; ++i)
        {
            scanf("%d%d%d%d",&a,&b,&c,&d);
            g[a][b].len=g[b][a].len=c;
            g[a][b].cost=g[b][a].cost=d;
        }
        scanf("%d%d",&s,&t);
        ans[s].len=ans[s].cost=0;
                for(i=1; i<=n; ++i){
                    for(j=1;j<=n;++j)
                    printf("%d:%d ",g[i][j].len,g[i][j].cost);
                    printf("\n");
                }
        for(i=s,k=1; k<=n; i=tmp,++k)
        {
            flag[i]=1;
            min=INT_MAX;
            for(j=1; j<=n; ++j)
            {
                if(flag[j]==1) continue;
                if(ans[j].len>g[i][j].len+ans[i].len&&g[i][j].len+ans[i].len>=0)
                {
                    ans[j].len=g[i][j].len+ans[i].len;
                    ans[j].cost=g[i][j].cost+ans[i].cost;
                    if(g[i][j].len<min)
                    {
                        min=g[i][j].len;
                        tmp=j;
                    }
                }
            }
        }
        for(i=1;i<=n;++i)
            printf("%d ",ans[i].len);

    }
}

