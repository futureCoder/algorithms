# include<stdio.h>
# include<string.h>
#include<stdlib.h>
int _res[1000];
void mul(char a[],char b[])
{
    int i,j,la,lb;
    la=strlen(a);
    lb=strlen(b);
    for (i=0; i<la+lb; i++)
        _res[i]=0;
    for (i=0; i<la; i++)
        for (j=0; j<lb; j++)
            _res[i+j+1]+=(a[i]-'0')*(b[j]-'0');
    //printf("\t\t");
    for (i=la+lb-1; i>0; i--)
    {
        if (_res[i]>=10)
        {
            _res[i-1]+=_res[i]/10;
            _res[i]%=10;
        }
        //printf("%d ",_res[i]);
    }
    //printf("%d",_res[0]);
    //printf("\n");
    //printf("la=%d\tlb=%d\t",la,lb);
    //for(i=0;i<la+lb;++i) printf("%c",_res[i]+'0');
    //printf("\n***************************************************\n");
    i=0;
    while (_res[i]==0)
        i++;
    for (j=0; i<la+lb; i++,j++)
        a[j]=_res[i]+'0';
    a[j]='\0';
    //free(s);
}
int main()
{
    char res[1000],r[10];
    int n;
    while(~scanf("%s %d",r,&n))
    {
        char m[10]= {0};
        int i,j,point=-1,judge=0;
        for(i=0; i<1000; ++i) res[i]=0;
        for(i=0,j=0; i<6; ++i)
            if(r[i]!='.') m[j++]=r[i];
            else point=strlen(r)-j-1;
        //for(i=5; r[i]!='.'; --i)
          //  judge|=(r[i]-'0');
        //point|=judge;
        //if(judge==0) 
        res[0]='1';
        point*=n;
        while(n--)
        {
            mul(res,m);
        }
        //printf("%s\n´¦ÀíÇ°¡ü*******************************************************\n",res);
        if(point>0)
        {
            for(i=0,j=strlen(res)-1; i<=j; ++i,--j) res[i]=res[i]+res[j]-(res[j]=res[i]);
            //res[i]='.';
            i=strlen(res);
            if(point>=i)
            {
                for(i=strlen(res); i<=point; ++i) res[i]='0';
                res[point]='.';
                res[point+1]=0;
            }
            else
            {
                while(i>=point)
                {
                    res[i]=res[i-1];
                    --i;
                }
                res[point]='.';
            }
            //printf("%s\n",res);
            for(i=0,j=strlen(res)-1; i<=j; ++i,--j) res[i]=res[i]+res[j]-(res[j]=res[i]);
            i=strlen(res)-1;
            while(res[i]=='0') res[i--]=0;
        }
        if(res[strlen(res)-1]=='.')res[strlen(res)-1]=0;
        printf("%s\n",res);
    }
}

