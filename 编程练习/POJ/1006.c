#include<stdio.h>
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int x,y,z,offset,i=1;
    while(~scanf("%d%d%d%d",&x,&y,&z,&offset)&&(x!=-1&&y!=-1&&z!=-1&&offset!=-1))
    {
        x%=23;
        y%=28;
        z%=33;
        int res=x;
        if(res==0) res+=23;
        while(res%23!=x||res%28!=y||res%33!=z) res+=23;
        res-=offset;
        if(res>21252) res%=21252;
        if(res<0) res+=21252;
        printf("Case %d: the next triple peak occurs in %d days.\n",i++,res);
    }
}
