#include<stdio.h>
typedef long long lld;
int main(){
lld m,a,b;
while(~scanf("%lld",&m)&&m){
scanf("%lld%lld",&a,&b);
char ans[100];
int len=0;
a+=b;
do{
ans[len++]=a%m;
a/=m;
}while(a);
while(len)
printf("%d",ans[--len]);
printf("\n");
}
}
