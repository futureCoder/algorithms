#include<stdio.h>
#include<string.h>

int main()
{   
    int n,i,j,flag,g,k,b[6],pos,spos,sum[200],key,temp[200],temp1[200];
    char a[7];
    memset(a,0x00,sizeof(a));
    while(scanf("%s %d",a,&n)!=EOF)
    {
        for(i=0;i<200;i++){sum[i]=0;temp1[i]=0;}
        j=0;
        flag=5;
        for(i=5;i>=0;i--)                
        {
            if(a[i]=='.')flag=i;
            else 
            {
                b[j]=a[i]-'0';
                temp1[j]=b[j];
                j++;
            }
        }            
        pos=0;
        spos=5;
        for(k=1;k<n;k++)
        {
            for(i=0;i<5;i++)
            {
                for(j=0;j<spos;j++)
                {
                    sum[i+j]+=(temp1[j]*b[i]);
                //    temp[i+j]=sum[i+j];
                //    sum[i+j]-=(temp1[j]*b[i]);
                }
            }
            key=sum[0]/10;
            sum[0]%=10;
            for(i=1;i<spos+4;i++)
            {
                sum[i]+=key;
                key=sum[i]/10;//printf("key=%d ",key);
                sum[i]%=10;//printf("sum=%d ",sum[i]);
            }
            sum[i]=key%10;//printf("sum=%d ",sum[i]);
            if(sum[i]!=0)pos++;
            i++;
            while((key/10)>0)
            {
                key/=10;
                sum[i]=key%10;
                pos++;//printf("add pos");
                i++;
            }
            spos=spos+4+pos;//printf("spos=%d ",spos);
            for(i=0;i<spos;i++){temp1[i]=sum[i];sum[i]=0;}//printf("temp1=%d  ",temp1[i]);}//printf("sum=%d ",sum[8]);
        }
        
        for(j=199;j>=(5-flag)*n;j--)
        {
            if(temp1[j]==0)continue;
            else
                break;
        }
        for(g=0;g<=(5-flag)*n-1;g++)
        {
            if(temp1[g]==0)continue;
            else
                break;
        }                    
        for(i=j;i>=(5-flag)*n;i--) 
        {
            printf("%d",temp1[i]);
        }
        if(g<(5-flag)*n)printf(".");
        for(i=(5-flag)*n-1;i>=g;i--)printf("%d",temp1[i]);
        printf("\n");                
    }
    return 0;
}
