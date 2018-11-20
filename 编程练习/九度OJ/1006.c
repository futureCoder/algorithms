#include<stdio.h>
#include<string.h>
int ac(char *s)
{
    int pos_z,pos_j,cz=0,cj=0,co=0,i,j,k,len=strlen(s);
    for(i=0; i<len; ++i)
        if(s[i]=='z') ++cz;
        else if(s[i]=='j') ++cj;
        else if(s[i]=='o') ++co;
    if(cz!=1||cj!=1||co==0) return 0;//Z和J只能有一个,o至少有一个
    pos_z=0;
    pos_j=len-1;
    while(pos_z<len) if(s[pos_z]!='z') ++pos_z;
        else break;
    while(pos_j>=0) if(s[pos_j]!='j') --pos_j;
        else break;
    if(pos_j-pos_z<0) return 0;//z在j前
    i=pos_z-0;
    j=pos_j-1-pos_z;
    k=len-1-pos_j;
    if(j==0) return 0;
    while(j!=1)
    {
        k-=i;
        --j;
    }
    if(i==k) return 1;
    else return 0;
}
int main()
{
    freopen("in.txt","r",stdin);
    char s[1001];
    while(~scanf("%s",s))
    {
        if(ac(s)) printf("Accepted\n");
        else printf("Wrong Answer\n");
    }
}
