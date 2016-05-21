#include <stdio.h>
#include <malloc.h>
#define N 3
int main(){
	int **nums = (int **)malloc(sizeof(int)*N*N);
	int a[N][N];
	int i,j;
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			scanf("%d",nums+i+j);
		}
	}
	for (i = 0; i < N; ++i)
	{
		for (j = 0; j < N; ++j)
		{
			printf("%d\n",nums+i+j);
		}
	}
}