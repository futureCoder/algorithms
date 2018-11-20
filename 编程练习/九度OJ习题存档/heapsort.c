#include<stdio.h>
void heapadjust(int array[],int i,int length){
int tmp,child;
for(tmp=array[i];2*i+1<length;i=child){
child=2*i+1;
if(child<length-1&&array[child+1]>array[child]) ++child;
if(tmp<array[child]){array[i]=array[child];array[child]=tmp;}
else break;
}
}
void heapsort(int array[],int length){
int i;
for(i=(length-1)/2;i>=0;--i)
heapadjust(array,i,length);
for(i=length-1;i>0;--i){
array[0]=array[0]+array[i]-(array[i]=array[0]);
heapadjust(array,0,i);
}
}
int main(){
int n;
while(~scanf("%d",&n)){
int a[n],i;
for(i=0;i<n;++i)
scanf("%d",&a[i]);
heapsort(a,n);
for(i=0;i<n;++i)
printf("%d%c",a[i],i==n-1?'\n':' ');
}
}
