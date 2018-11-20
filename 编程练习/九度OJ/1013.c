#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    freopen("in.txt","r",stdin);
    while(~scanf("%d",&n))
    {
        int i,j,m,min,max,sh,sm,ss,eh,em,es;
        char e[20],l[20],tmp[20];
        for(i=0; i<n; ++i)
        {
            scanf("%d",&m);
            for(j=0,min=250000,max=-1; j<m; ++j)
            {
                scanf("%s %d:%d:%d %d:%d:%d",tmp,&sh,&sm,&ss,&eh,&em,&es);
                if(sh*10000+sm*100+ss<min)
                {
                    min=sh*10000+sm*100+ss;
                    strcpy(e,tmp);
                }
                if(eh*10000+em*100+es>max)
                {
                    max=eh*10000+em*100+es;
                    strcpy(l,tmp);
                }
            }
            printf("%s %s\n",e,l);
        }
    }
}
