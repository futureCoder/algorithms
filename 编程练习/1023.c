#include<stdio.h>
#include<stdlib.h>
typedef struct record{
char no[7];
char name[9];
int score;
}record;
int _c;
int cmp(const void *a,const void *b){
record c=*(record *)a;
record d=*(record *)b;
int _no=strcmp(c.no,d.no),_name=strcmp(c.name,d.name),_score=c.score-d.score;
switch(_c){
case 1:return _no;break;
case 2:if(_name!=0) return _name;else return _no;break;
case 3:if(_score!=0) return _score;else return _no;break;
default:break;
}
}
int main(){
int i,n,j=1;
while(~scanf("%d",&n)&&n){
scanf("%d",&_c);
record stu[n];
for(i=0;i<n;++i)
scanf("%s%s%d",stu[i].no,stu[i].name,&stu[i].score);
qsort(stu,n,sizeof(record),cmp);
printf("Case %d:\n",j++);
for(i=0;i<n;++i)
printf("%s %s %d\n",stu[i].no,stu[i].name,stu[i].score);
}
}
