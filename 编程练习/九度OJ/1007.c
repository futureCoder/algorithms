#include<stdio.h>
int main()
{
    int n,m;
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&n,&m))
    {
        double t1,t2,t3,s[n][4];
        int i,j,r[m];
        for(i=0; i<n; ++i)
        {
            scanf("%lf%lf%lf",&t1,&t2,&t3);
            s[i][0]=t1;
            s[i][1]=t2;
            s[i][2]=t1/t3;
            s[i][3]=t2/t3;
        }
        for(i=0; i<m; ++i)
            scanf("%d",&r[i]);
        for(i=0; i<m; ++i)
        {
            int g[4]= {1,1,1,1};
            for(j=0; j<m; ++j)
            {
                if(s[r[i]][0]<s[r[j]][0]) ++g[0];
                if(s[r[i]][1]<s[r[j]][1]) ++g[1];
                if(s[r[i]][2]<s[r[j]][2]) ++g[2];
                if(s[r[i]][3]<s[r[j]][3]) ++g[3];
            }
            int manner,min=m+2;
            for(j=0; j<4; ++j)
                if(g[j]<min)
                {
                    min=g[j];
                    manner=j+1;
                }
            printf("%d:%d\n",min,manner);
        }
        printf("\n");
    }
}
