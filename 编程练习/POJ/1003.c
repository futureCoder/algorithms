#include<stdio.h>
#include<math.h>
#define EPS 1e-8
int main(){
double c;
freopen("in.txt","r",stdin);
while(~scanf("%lf",&c)&&fabs(c)>EPS){
int cnt=0,i=2;
double tmp=0;
do{
tmp+=1/(double)i;
++i;
}while(tmp<c);
printf("%d card(s)\n",i-2);
}
}
