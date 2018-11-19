#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,m;
    while(~scanf("%d",&n))
    {
        while(n--)
        {
            scanf("%d",&m);
            char peo[m][16];
            int i,sh,sm,ss,eh,em,es,ts,te,st=250000,en=0,s,e;
            for(i=0; i<m; ++i)
            {
                scanf("%s %d:%d:%d %d:%d:%d",peo[i],&sh,&sm,&ss,&eh,&em,&es);
                ts=ss+sm*100+sh*10000;
                te=es+em*100+eh*10000;
                if(ts<=st)
                {
                    st=ts;
                    s=i;
                }
                if(te>=en)
                {
                    en=te;
                    e=i;
                }
            }
            printf("%s %s\n",peo[s],peo[e]);
        }
    }
}
