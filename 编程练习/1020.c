#include<stdio.h>
int main(){
  int x,y,x1,y1,x2,y2;
  while(~scanf("%d%d",&x1,&y1)&&(x1||y1)){
    x2=x1,y2=y1;
    while(~scanf("%d%d",&x,&y)&&(x||y)){
      if(x<x1) x1=x;
      if(x>x2) x2=x;
      if(y<y1) y1=y;
      if(y>y2) y2=y;
}
    printf("%d %d %d %d\n",x1,y1,x2,y2);
}
}
