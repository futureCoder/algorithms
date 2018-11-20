#include<stdio.h>
int main(){
freopen("in.txt","r",stdin);
int i;
float mon,tmp;
for(i=0,tmp=0;i<12;++i){
scanf("%f",&mon);
tmp+=mon;
}
tmp/=12.0;
printf("$%.2f",tmp);
}
