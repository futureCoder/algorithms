#include<stdio.h>
typedef long long lld;
lld ans(int n){
if(n<=1) return 1;
else return n*ans(n-1);
}
int main(){
int n;
while(~scanf("%d",&n))
printf("%lld\n",ans(n));
}
