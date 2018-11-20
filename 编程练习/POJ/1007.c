#include<stdio.h>
#include<string.h>
typedef struct dna
{
    char s[51];
    int num;
} dna;
int cmp(const void *a,const void *b)
{
    dna c=*(dna *)a,d=*(dna *)b;
    return c.num-d.num;
}
int inversion(char *a,int len)
{
    int i,j,cnt=0;
    for(i=0; i<len; ++i)
        for(j=i; j<len; ++j)
            if(a[i]>a[j]) ++cnt;
    return cnt;
}
int main()
{
    freopen("in.txt","r",stdin);
    int len,m,i,j;
    while(~scanf("%d%d",&len,&m))
    {
        dna obj[m];
        for(i=0; i<m; ++i)
        {
            scanf("%s",obj[i].s);
            obj[i].num=inversion(obj[i].s,len);
        }
        qsort(obj,m,sizeof(dna),cmp);
        for(i=0; i<m; ++i)
            printf("%s\n",obj[i].s);
    }
}
