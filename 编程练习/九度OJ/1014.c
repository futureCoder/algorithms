#include<stdio.h>
typedef struct student
{
    char no[25];
    int acnum;
    int score;
} student;
int cmp(const void *a,const void *b)
{
    student c=*(student *)a;
    student d=*(student *)b;
    if(c.score!=d.score) return d.score-c.score;
    else if(c.score==d.score) return strcmp(c.no,d.no);
}

int main()
{
    int n,m,g;
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&n,&m,&g)&&n)
    {
        int value[m],i,j,count=0,tmp;
        student stu[n];
        memset(value,0,sizeof(value));
        for(i=0; i<m; ++i)
            scanf("%d",value+i);
        for(i=0; i<n; ++i)
        {
            scanf("%s%d",stu[i].no,&stu[i].acnum);
            for(j=0,stu[i].score=0; j<stu[i].acnum; ++j)
            {
                scanf("%d",&tmp);
                stu[i].score+=value[tmp-1];
            }
            if(stu[i].score>=g) ++count;
        }
        qsort(stu,n,sizeof(student),cmp);
        printf("%d\n",count);
        for(i=0; i<count; ++i)
            printf("%s %d\n",stu[i].no,stu[i].score);
    }
}
