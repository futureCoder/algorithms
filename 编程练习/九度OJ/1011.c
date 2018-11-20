#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        int s,e,ts,te,tss,tmp,i,sum,max;
        scanf("%d",&tmp);
        sum=max=ts=tss=te=s=e=tmp;
        for(i=1; i<n; ++i)
        {
            scanf("%d",&tmp);
            if(sum>0)
            {
                sum+=tmp;
                te=tmp;
            }
            else
            {
                sum=tmp;
                ts=te=tmp;
            }
            if(sum>max)
            {
                s=ts;
                e=te;
                max=sum;
            }
        }
        if(max<0) printf("0 %d %d\n",tss,te);
        else if(max==0) printf("0 0 0\n");
        else printf("%d %d %d\n",max,s,e);
    }
}
