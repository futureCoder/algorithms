#include<stdio.h>
int main()
{
    int n,m;
    while(~scanf("%d",&n)&&n)
    {
        scanf("%d",&m);
        int i,j,k=2,a[n][m],b[n][m],flag,count=0;
        for(i=0; i<n; ++i)
            for(j=0; j<m; ++j)
                scanf("%d",&a[i][j]);
        for(i=0; i<n; ++i)
            for(j=0; j<m; ++j)
                scanf("%d",&b[i][j]);
        for(i=0; i<n; ++i)
            for(j=0; j<m; ++j)
                a[i][j]+=b[i][j];
        for(i=0; i<n; ++i)
        {flag=0;
            for(j=0; j<m; ++j)
                flag=flag||a[i][j];
            if(!flag) ++count;
        }
        for(j=0; j<m; ++j)
        {flag=0;
            for(i=0; i<n; ++i)
                flag=flag||a[i][j];
            if(!flag) ++count;
        }
        printf("%d\n",count);
    }
}
