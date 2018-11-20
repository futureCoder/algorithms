#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int main()
{
    int p,t,g1,g2,g3,gj;
    while(~scanf("%d%d%d%d%d%d",&p,&t,&g1,&g2,&g3,&gj))
    {
        double ans;
        int g12=abs(g1-g2),g13=abs(g1-g3),g23=abs(g2-g3),max;
        if(g12<=t) ans=(g1+g2)/2.0;
        else if(g13<=t&&g23<=t)
        {
            max=g1;
            if(g2>max) max=g2;
            if(g3>max) max=g3;
            ans=(double)max;
        }
        else if(g13<=t||g23<=t)
        {
            if(g13<g23) ans=(g1+g3)/2.0;
            else ans=(g2+g3)/2.0;
        }
        else if(g13>t&&g23>t) ans=gj;
        printf("%.1lf\n",ans);
    }
}
