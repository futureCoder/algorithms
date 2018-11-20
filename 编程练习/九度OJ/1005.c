#include<stdio.h>
#define MAXCHOI 5
typedef struct student
{
    int no;
    int ge;
    int gi;
    int gf;
    int choi[MAXCHOI];
    int school;
} student;
int cmp_grade(const void *a,const void *b)
{
    student c=*(student *)a,d=*(student *)b;
    if(d.gf-c.gf!=0) return d.gf-c.gf;
    else return d.ge-c.ge;
}
int cmp_school(const void *a,const void *b)
{
    student c=*(student *)a,d=*(student *)b;
    if(c.school-d.school!=0) return c.school-d.school;
    else return c.no-d.no;
}
int main()
{
    int n,m,k;
    freopen("in.txt","r",stdin);
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        int quota[m];
        int i,j,l,now=0;
        student stu[n];
        for(i=0; i<m; ++i)
            scanf("%d",quota+i);
        for(i=0; i<n; ++i)
        {
            stu[i].no=i;
            scanf("%d%d",&stu[i].ge,&stu[i].gi);
            stu[i].gf=(stu[i].ge+stu[i].gi)/2;
            for(j=0; j<k; ++j)
                scanf("%d",&stu[i].choi[j]);
        }
        qsort(stu,n,sizeof(student),cmp_grade);
        for(i=0; i<n; ++i)
        {
            for(j=0; j<k; ++j)
            {
                if(quota[stu[i].choi[j]]>0)
                {
                    stu[i].school=stu[i].choi[j];
                    --quota[stu[i].choi[j]];
                    break;
                }
                else if(i-1>=0&&(stu[i].gf==stu[i-1].gf&&stu[i].ge==stu[i-1].ge)&&stu[i].choi[j]==stu[i-1].school)
                {
                    stu[i].school=stu[i-1].school;
                    --quota[stu[i-1].school];
                    break;
                }
                else if(j==k-1) stu[i].school=-1;
            }
        }
        qsort(stu,n,sizeof(student),cmp_school);
        for(j=0; j<m; ++j)
        {
            for(i=now; i<n; ++i)
                if(stu[i].school==j)
                {
                    if((i-1>=0&&stu[i-1].school!=j)||i==0)printf("%d",stu[i].no);
                    else printf(" %d",stu[i].no);
                }
                else if(stu[i].school>j)
                {
                    printf("\n");
                    now=i;
                    break;
                }
        }
        printf("\n");
    }
}
