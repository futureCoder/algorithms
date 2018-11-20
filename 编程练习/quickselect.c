#include <stdio.h>
#include <stdlib.h>
int main(){
int n;
while(~scanf("%d",&n)){
int a[n],k,i;
for(i=0;i<n;++i)
scanf("%d",a+i);
scanf("%d",&k);
printf("第%d小的数字是%d\n",k,quickselect(a,0,n-1,k-1));
}
}

int quickselect(int array[],int left,int right,int k){
if(left>=right) return 0;
int i,j,orient;
for(i=left,j=right,orient=1;i!=j;i+=orient)
if(orient*(array[i]-array[j])>0){
array[i]=array[i]+array[j]-(array[j]=array[i]);
i=i+j-(j=i);
orient*=-1;
}
if(i==k) return array[i];
if(i>k) return quickselect(array,left,i-1,k);
if(i<k) return quickselect(array,i+1,right,k);
}
