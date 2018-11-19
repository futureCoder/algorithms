#include<stdio.h>
#include<string.h>
long long convert(char str[11])
{
    int t=1,len=strlen(str);
    long long rtn=0;
    while(--len>=0)
    {
        if(str[len]==',') continue;
        else if(str[len]=='-') rtn*=-1;
        else rtn+=t*(str[len]-'0');
        t*=10;
    }
    return rtn;
}
int main()
{
    char a[20],b[20];
    while(~scanf("%s%s",a,b))
    {
        long long n1=convert(a),n2=convert(b);
        printf("%lld\n",n1+n2);
    }
}
