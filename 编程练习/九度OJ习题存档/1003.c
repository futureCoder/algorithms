#include<stdio.h>
#include<string.h>
int convert(char s[])
{
    int ans,w,i,l=strlen(s);
    for(w=1,ans=0,i=l-1; i>0; --i)
        if(s[i]!=',')
        {
            ans+=(s[i]-'0')*w;
            w*=10;
        }
        else continue;
    if(s[0]!='-') ans+=(s[i]-'0')*w;
    else ans*=-1;
    return ans;
}
int main()
{
    char sa[20],sb[20];
    while(~scanf("%s%s",sa,sb))
    {
        int a=convert(sa),b=convert(sb);
        printf("%d\n",a+b);
    }
}
