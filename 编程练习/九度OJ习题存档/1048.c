#include<stdio.h>
void swap(int *a,int *b){
*a=*a+*b-(*b=*a);
}
int main(){
int a,b,c;
while(~scanf("%d%d%d",&a,&b,&c)){
int i=2;
while(i--){
if(a>b) swap(&a,&b);
if(b>c) swap(&b,&c);
}
if(a*a+b*b==c*c) printf("直角三角形\n");
else if(a*a+b*b>c*c) printf("锐角三角形\n");
else printf("钝角三角形\n");
}
}
