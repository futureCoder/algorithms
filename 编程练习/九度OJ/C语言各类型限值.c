#include <conio.h>
#include<stdio.h>
//#include <sio.h>
#include <limits.h>
#include <float.h>
#include<windows.h>

int main(void)
{
system("cls");
printf("char��λ��:%u\n",CHAR_BIT);
printf("char���͵����ֵ:%d\n",CHAR_MAX);
printf("char���͵���Сֵ:%d\n",CHAR_MIN);
printf("signed char���͵����ֵ:%d\n",SCHAR_MAX);
printf("signed char���͵���Сֵ:%d\n",SCHAR_MIN);
printf("unsigned char���͵����ֵ:%u\n",UCHAR_MAX);
getch();
system("cls");
printf("short���͵����ֵ:%hd\n",SHRT_MAX);
printf("short���͵���Сֵ:%hd\n",SHRT_MIN);
printf("unsigned short���͵����ֵ:%u\n",USHRT_MAX);
getch();
system("cls");
printf("int���͵����ֵ:%d\n",INT_MAX);
printf("int���͵���Сֵ:%d\n",INT_MIN);
printf("unsigned int���͵����ֵ:%u\n",UINT_MAX);
getch();
system("cls");
printf("long���͵����ֵ:%ld\n",LONG_MAX);
printf("long���͵���Сֵ:%ld\n",LONG_MIN);
printf("unsigned long���͵���Сֵ:%lu\n",ULONG_MAX);
getch();
system("cls");
printf("float���͵�β��λ��:%u\n",FLT_MANT_DIG);
printf("float���͵���С��Ч����λ��:%u\n",FLT_DIG);
printf("����ȫ����Ч����λ����float���͵ĸ�ָ������Сֵ:%d\n",FLT_MAX_10_EXP);
printf("����ȫ����Ч����λ����float���͵���ָ�������ֵ:%d\n",FLT_MIN_10_EXP);
printf("����ȫ�����ȵ�float������������Сֵ:%e\n",FLT_MIN);
printf("����ȫ�����ȵ�float�������������ֵ:%e\n",FLT_MAX);
printf("1.00�ͱ�1.00�����С��float����ֵ֮��Ĳ�ֵ:%e\n",FLT_EPSILON);
getch();
system("cls");
printf("double���͵�β��λ��:%u\n",DBL_MANT_DIG);
printf("double���͵���С��Ч����λ��:%u\n",DBL_DIG);
printf("����ȫ����Ч����λ����double���͵ĸ�ָ������Сֵ:%u\n",DBL_MAX_10_EXP);
printf("����ȫ����Ч����λ����double���͵���ָ�������ֵ:%d\n",DBL_MIN_10_EXP);
printf("����ȫ�����ȵ�double������������Сֵ:%e\n",DBL_MIN);
printf("����ȫ�����ȵ�double������������Сֵ:%e\n",DBL_MAX);
printf("1.00�ͱ�1.00�����С��double����ֵ֮��Ĳ�ֵ:%e\n",DBL_EPSILON);
getch();
system("cls");
printf("long double���͵�β��λ��:%d\n",LDBL_MANT_DIG);
printf("long double���͵���С��Ч����λ��:%d\n",LDBL_DIG);
printf("����ȫ����Ч����λ����long double���͵ĸ�ָ�������ֵ:%d\n",LDBL_MAX_10_EXP);
printf("����ȫ����Ч����λ����long double���͵���ָ������Сֵ:%d\n",LDBL_MIN_10_EXP);
printf("����ȫ�����ȵ�long double������������Сֵ:%le\n",LDBL_MIN);
printf("����ȫ�����ȵ�long double�������������ֵ:%le\n",LDBL_MAX);
printf("1.00�ͱ�1.00�����С��long double����ֵ֮��Ĳ�ֵ:%le\n",LDBL_EPSILON);

getch();
return 0;
}
