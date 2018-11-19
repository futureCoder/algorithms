#include<stdio.h>
#define max 100
int a[max][max];
int main(){
int n;
while(~scanf("%d",&n)&&n){
int i,j,k,ans=0;
for(i=1;i<=n;++i)
for(j=1;j<=n;++j)
a[i][j]=i==j?0:0x0fffffff;
for(k=0;k<n*(n-1)/2;++k){
scanf("%d%d",&i,&j);
scanf("%d",&a[i][j]);
a[j][i]=a[i][j];
}
for(i=1;i<=n;++i)
for(j=1;j<=n;++j)
for(k=1;k<=n;++k)
if(i!=j&&a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];
for(i=1;i<=n;++i)
for(j=1;j<=n;++j){
for(k=1;k<=n;++k)
if(i!=j&&a[i][j]>a[i][k]+a[k][j]) a[i][j]=a[i][k]+a[k][j];
if(a[i][j]>ans) ans=a[i][j];
}
printf("%d\n",ans);
}
}
