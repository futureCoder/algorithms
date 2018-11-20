#include<stdio.h>
int main()
{
    int i,n,t;
    while(~scanf("%d",&n)&&n)
    {
        int hash[101]= {0};
        for(i=0; i<n; ++i)
        {
            scanf("%d",&t);
            ++hash[t];
        }
        scanf("%d",&t);
        printf("%d\n",hash[t]);
    }
}
