#include<stdio.h>
int main()
{
    int m,n;
    //freopen("in.txt","r",stdin);
    while(~scanf("%d%d",&m,&n)&&m)
    {
        int matrix[m][n],i,j,k,temp,ans=0,flag=0;
        for(i=0; i<m; ++i)
            for(j=0; j<n; ++j)
                matrix[i][j]=0;
        for(k=0; k<2; ++k)
            for(i=0; i<m; ++i)
                for(j=0; j<n; ++j)
                {
                    scanf("%d",&temp);
                    matrix[i][j]+=temp;
                }
        for(i=0; i<m; ++i)
        {
            flag=0;
            for(j=0; j<n; ++j)
                flag|=matrix[i][j];
            if(!flag) ++ans;
        }
        for(j=0; j<n; ++j)
        {
            flag=0;
            for(i=0; i<m; ++i)
                flag|=matrix[i][j];
            if(!flag) ++ans;
        }
        printf("%d\n",ans);
    }
}
