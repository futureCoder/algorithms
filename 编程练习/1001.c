#include<stdio.h>
#define MAX 10
int main()
{
    int a[MAX][MAX],b[MAX][MAX],m,n,i,j,count,t;
    while(~scanf("%d",&m)&&m)
    {
        scanf("%d",&n);
        for(i=0; i<m; ++i)
            for(j=0; j<n; ++j)
                scanf("%d",&a[i][j]);
        for(i=0; i<m; ++i)
            for(j=0; j<n; ++j)
                scanf("%d",&b[i][j]);
        for(i=0; i<m; ++i)
            for(j=0; j<n; ++j)
                a[i][j]+=b[i][j];
        count=0;
        for(i=0; i<m; ++i)
        {
            t=0;
            for(j=0; j<n; ++j)
                t|=a[i][j];
            if(t==0) ++count;
        }
        for(j=0; j<n; ++j)
        {
            t=0;
            for(i=0; i<m; ++i)
                t|=a[i][j];
            if(t==0) ++count;
        }
        printf("%d\n",count);
    }
}
