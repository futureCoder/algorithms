#include<stdio.h>
#include<string.h>
int main(){
char s[1001];
while(~scanf("%s",s)){
int len=strlen(s),i,flag=0,f,r;
if(len<=3) if(!strcmp(s,"zoj")) flag=1;else;//case1
else {
for(i=0;s[i]!='j';++i)
if(s[i]=='z') f=i;
r=i;
if(r-f==2&&s[r+1]=='o'&&f>0&&r<len) {if(f==len-r-1)flag=1;}//case2
else {for(i=0;i<len;++i) if(i!=f&&i!=r) flag|=s[i];//case3
if(flag=='o'&&((f>0&&r<len-1)||(f==0&&r==len-1))) flag=1;
else flag=0;
}
}
printf("%s\n",flag?"Accepted":"Wrong Answer");
}
}
