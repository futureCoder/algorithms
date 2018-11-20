#include<stdio.h>
int gcd(int a,int b){
if(a==0) return b;
else return gcd(b%a,a);
}
int main(){
int a,b;
while(~scanf("%d%d",&a,&b))
printf("%d\n",gcd(a,b));
}
