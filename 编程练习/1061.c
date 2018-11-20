#include<stdio.h>//¿ìÅÅº¯Êı
#include<stdlib.h>
typedef struct student
{
    char name[101];
    int age;
    int score;
} student;
int cmp(const void *a,const void *b)
{
    student c=*(student *)a,d=*(student *)b;
    int sc=c.score-d.score,na=strcmp(c.name,d.name),ag=c.age-d.age;
    if(sc) return sc;
    else if(na) return na;
    else return ag;
}
void main()
{
    int n;
    while(~scanf("%d",&n))
    {
        student stu[n];
        int i;
        for(i=0; i<n; ++i)
            scanf("%s%d%d",stu[i].name,&stu[i].age,&stu[i].score);
        qsort(stu,n,sizeof(student),cmp);
        for(i=0; i<n; ++i)
            printf("%s %d %d\n",stu[i].name,stu[i].age,stu[i].score);
    }
}
