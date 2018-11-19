#include<stdio.h>//¿ìÅÅº¯Êý
#include<stdlib.h>
int cmp(const void *a,const void *b)
{
    return *(int *)a-*(int *)b;
}
void main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int i,num[n];
        for(i=0; i<n; ++i)
            scanf("%d",num+i);
        qsort(num,n,sizeof(int),cmp);
        for(i=0; i<n; ++i)
            printf("%d ",num[i]);
        printf("\n");
    }
}
