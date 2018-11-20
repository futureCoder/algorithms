#include <conio.h>
#include<stdio.h>
//#include <sio.h>
#include <limits.h>
#include <float.h>
#include<windows.h>

int main(void)
{
system("cls");
printf("char的位数:%u\n",CHAR_BIT);
printf("char类型的最大值:%d\n",CHAR_MAX);
printf("char类型的最小值:%d\n",CHAR_MIN);
printf("signed char类型的最大值:%d\n",SCHAR_MAX);
printf("signed char类型的最小值:%d\n",SCHAR_MIN);
printf("unsigned char类型的最大值:%u\n",UCHAR_MAX);
getch();
system("cls");
printf("short类型的最大值:%hd\n",SHRT_MAX);
printf("short类型的最小值:%hd\n",SHRT_MIN);
printf("unsigned short类型的最大值:%u\n",USHRT_MAX);
getch();
system("cls");
printf("int类型的最大值:%d\n",INT_MAX);
printf("int类型的最小值:%d\n",INT_MIN);
printf("unsigned int类型的最大值:%u\n",UINT_MAX);
getch();
system("cls");
printf("long类型的最大值:%ld\n",LONG_MAX);
printf("long类型的最小值:%ld\n",LONG_MIN);
printf("unsigned long类型的最小值:%lu\n",ULONG_MAX);
getch();
system("cls");
printf("float类型的尾数位数:%u\n",FLT_MANT_DIG);
printf("float类型的最小有效数字位数:%u\n",FLT_DIG);
printf("带有全部有效数字位数的float类型的负指数的最小值:%d\n",FLT_MAX_10_EXP);
printf("带有全部有效数字位数的float类型的正指数的最大值:%d\n",FLT_MIN_10_EXP);
printf("保留全部精度的float类型正数的最小值:%e\n",FLT_MIN);
printf("保留全部精度的float类型正数的最大值:%e\n",FLT_MAX);
printf("1.00和比1.00大的最小的float类型值之间的差值:%e\n",FLT_EPSILON);
getch();
system("cls");
printf("double类型的尾数位数:%u\n",DBL_MANT_DIG);
printf("double类型的最小有效数字位数:%u\n",DBL_DIG);
printf("带有全部有效数字位数的double类型的负指数的最小值:%u\n",DBL_MAX_10_EXP);
printf("带有全部有效数字位数的double类型的正指数的最大值:%d\n",DBL_MIN_10_EXP);
printf("保留全部精度的double类型正数的最小值:%e\n",DBL_MIN);
printf("保留全部精度的double类型正数的最小值:%e\n",DBL_MAX);
printf("1.00和比1.00大的最小的double类型值之间的差值:%e\n",DBL_EPSILON);
getch();
system("cls");
printf("long double类型的尾数位数:%d\n",LDBL_MANT_DIG);
printf("long double类型的最小有效数字位数:%d\n",LDBL_DIG);
printf("带有全部有效数字位数的long double类型的负指数的最大值:%d\n",LDBL_MAX_10_EXP);
printf("带有全部有效数字位数的long double类型的正指数的最小值:%d\n",LDBL_MIN_10_EXP);
printf("保留全部精度的long double类型正数的最小值:%le\n",LDBL_MIN);
printf("保留全部精度的long double类型正数的最大值:%le\n",LDBL_MAX);
printf("1.00和比1.00大的最小的long double类型值之间的差值:%le\n",LDBL_EPSILON);

getch();
return 0;
}
