#include<stdio.h>
#include<string.h>
int main(){
	//double t=0;
	short x;
	//printf("%d--%d",sizeof(float),sizeof(short));
	printf("32bit浮点->整型运算计算器\n");
	while(~scanf("%d",&x)){
	//unsigned long long lx=0;
	int x1 = x<<16;
	float t;
	memcpy(&t,&x1,4);
	//unsigned int x1 = 0,x2 = 0;
	//x1 = lx>>32;
	//x2 = lx;
//	printf("%lld\n",lx);
	printf("%f\n",t);
}
}
