#include<stdio.h>
void heapadjust(int array[],int i,int length)
{
    int nchild,tmp;
    for(tmp=array[i]; 2*i+1<length; i=nchild)
    {
        nchild=2*i+1;
        if(nchild+1<length&&array[nchild+1]>array[nchild]) ++nchild;
        if(array[nchild]>tmp)
        {
            array[i]=array[nchild];
            array[nchild]=tmp;
        }
        else continue;
    }
}
void heapsort(int array[],int length)
{
    int i;
    for(i=(length-1)/2; i>=0; --i)
        heapadjust(array,i,length);
    for(i=length-1; i>0; --i)
    {
        array[0]=array[0]+array[i]-(array[i]=array[0]);
        heapadjust(array,0,i);
    }
}
int main()
{
    int n,i;
    while(~scanf("%d",&n))
    {
        int a[n];
        for(i=0; i<n; ++i)
            scanf("%d",a+i);
        heapsort(a,n);
        for(i=0; i<n; ++i)
            printf("%d ",a[i]);
    }
}
