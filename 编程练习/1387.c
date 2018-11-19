#include<stdio.h>
#include<string.h>
int main(){
int i,n;
long long ans[71];
ans[0]=0;
ans[1]=1;
for(i=2;i<=70;++i)
ans[i]=ans[i-1]+ans[i-2];
while(~scanf("%d",&n)){
printf("%lld\n",ans[n]);
}
}
