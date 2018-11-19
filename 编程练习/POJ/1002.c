#include<stdio.h>
#include<string.h>
int cmp(const void *a,const void *b){
char *c=(char *)a,*d=(char *)b;
return strcmp(c,d);
}
void trans(char *a,char*b){
int i,j;
for(i=0,j=0;b[j]!=0&&i<7;++j)
if(b[j]>='0'&&b[j]<='9') a[i++]=b[j];
else switch(b[j]){
case 'A':case 'B':case 'C': a[i++]='2';break;
case 'D':case 'E':case 'F': a[i++]='3';break;
case 'G':case 'H':case 'I': a[i++]='4';break;
case 'J':case 'K':case 'L': a[i++]='5';break;
case 'M':case 'N':case 'O': a[i++]='6';break;
case 'P':case 'R':case 'S': a[i++]='7';break;
case 'T':case 'U':case 'V': a[i++]='8';break;
case 'W':case 'X':case 'Y': a[i++]='9';break;
default: break;
}
a[7]=0;
}
int main(){
//FILE *fp;
//fp=freopen("in.txt","r",stdin);
int n;
while(~scanf("%d",&n)){
char str[n][8],tmp[50];
int i,j,cnt=-1,s[n],flag=0;
for(i=0;i<n;++i){
scanf("%s",tmp);
trans(str[i],tmp);
s[i]=0;
}
qsort(str,n,sizeof(str[0]),cmp);
for(i=1;i<n;++i)
if(strcmp(str[i-1],str[i])==0) {s[i]=s[i-1]+1;s[i-1]=0;}
for(i=0;i<n;i++){flag|=s[i];
if(s[i]!=0) {for(j=0;j<3;++j)printf("%c",str[i][j]);printf("-");for(;j<7;++j)printf("%c",str[i][j]);
printf(" %d\n",s[i]+1);
}
else if(i==n-1&&flag==0) printf("No duplicates.\n");
}
}
}
