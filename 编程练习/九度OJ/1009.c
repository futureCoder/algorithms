#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct node
{
    char c;
    struct node *l,*r;
} node;
node *newnode(char *s){
node *t;
t=(node *)malloc(sizeof(node));
t->c=*s;
t->l=t->r=NULL;
return t;
}
void build(node *t,char *s)
{
    if(t->c==0) t->c=*s;
    while(s>t->c)
}
void preorder(node *t)
{
    if(t!=NULL)
    {
        printf("%c",t->c);
        if(t->l) preorder(t->l);
        if(t->r) preorder(t->r);
    }
}
int main()
{
    char s[15],s1[15];
    int n;
    while(~scanf("%d",&n))
    {
        node *t;
        scanf("%s",s);
        t=newnode(s);
        build(t,s);
        preorder(t);
    }
}
