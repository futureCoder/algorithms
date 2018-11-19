#include<stdio.h>
int fb(int n){
if(n==0||n==1) return n;
else return fb(n-1)+fb(n-2);
}
int main(){
int n;
while(~scanf("%d",&n)){
printf("%d\n",fb(n));
}
}
