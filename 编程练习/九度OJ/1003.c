#include<stdio.h>
#include<string.h>
typedef long long lld;
lld stoi(char* s)
{
    int l=strlen(s);
    lld w=1,rtn=0;
    while(l--)
    {
        if(s[l]==',') continue;
        if(s[l]>='0'&&s[l]<='9') rtn+=(s[l]-'0')*w;
        w*=10;
        if(s[l]=='-') rtn*=-1;
    }
    return rtn;
}
int main()
{
    freopen("in.txt","r",stdin);
    char sa[20],sb[20];
    while(~scanf("%s%s",sa,sb))
    {
        int a=stoi(sa),b=stoi(sb);
        printf("%d\n",a+b);
    }
}
