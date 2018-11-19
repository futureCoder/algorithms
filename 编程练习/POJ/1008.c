#include<stdio.h>
#include<string.h>
char haab_month[19][10]={"pop","no","zip","zotz","tzec","xul","yoxkin","mol","chen","yax","zac","ceh","mac","kankin","muan","pax","koyab","cumhu","uayet"};
char tzolkin_day[20][10]={"imix","ik","akbal","kan","chicchan","cimi","manik","lamat","muluk","ok","chuen","eb","ben","ix","mem","cib","caban","eznab","canac","ahau"};
int main(){
freopen("in.txt","r",stdin);
int n,i,j;
while(~scanf("%d",&n)){
printf("%d\n",n);
for(i=0;i<n;++i){
int date,year,day;
char month[10];
scanf("%d.%s%d",&date,month,&year);
for(j=0;j<19;++j)
if(strcmp(haab_month[j],month)==0) break;
day=year*365+20*j+date;
year=day/260;
day=day%260;
strcpy(month,tzolkin_day[day%20]);
day=day%13+1;
date=day;
printf("%d %s %d\n",date,month,year);
}
}
}
