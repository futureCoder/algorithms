#include<stdio.h>
int main()
{
    int n;
    while(~scanf("%d",&n))
    {
        int a,min,i;
        for(i=0; i<n; ++i)
        {
            scanf("%d",&a);
            if(i==0) min=a;
            if(min>a) min=a;
        }
        printf("%d\n",min);
    }
}
