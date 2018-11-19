#include <stdio.h>
void heapadjust(int array[],int i,int length){
int nChild=2*i+1,tmp;
if(nChild+1<length&&array[nChild+1]>array[nChild]) ++nChild;
for(tmp=array[i];2*nChild+1<=length;nChild=2*i+1)
if(array[i]<array[nChild]) {array[i]=array[nChild];array[nChild]=tmp;i=nChild;}
else break;

}

void heapsort(int array[],int length){
int i;
for(i=(length-1)/2;i>=0;--i)
heapadjust(array,i,length);
for(i=length-1;i>0;--i){
array[0]=array[i]+array[0]-(array[i]=array[0]);
heapadjust(array,0,i);
}
}

int main(){
int n;
while(~scanf("%d",&n)){
int array[n],i;
for(i=0;i<n;++i)
scanf("%d",&array[i]);
heapsort(array,n);
for(i=0;i<n;++i)
printf("%d ",array[i]);
printf("\n");
}
}
