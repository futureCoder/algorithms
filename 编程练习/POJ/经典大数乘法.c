# include<stdio.h>
# include<string.h>
# include<malloc.h>
void multiply(char* a,char* b,char* c)
{
    int i,j,la,lb,* s;
    la=strlen(a);
    lb=strlen(b);
    s=(int*)malloc(sizeof(int)*(la+lb));
    for (i=0;i<la+lb;i++)
        s[i]=0;
    for (i=0;i<la;i++)
        for (j=0;j<lb;j++)
            s[i+j+1]+=(a[i]-'0')*(b[j]-'0');
    for (i=la+lb-1;i>=0;i--)
        if (s[i]>=10)
        {
            s[i-1]+=s[i]/10;
            s[i]%=10;
        }
    i=0;
    while (s[i]==0)
        i++;
       for (j=0;i<la+lb;i++,j++)
           c[j]=s[i]+'0';
    c[j]='\0';
    free(s);
}
int main(){
char a[20],b[20],c[50];
while(~scanf("%s %s",a,b)){
	multiply(a,b,c);
	printf("%s\n",c);
	}
}	

