#include<stdio.h>
#include<math.h>
#include<time.h>
#define pi 3.14
#define true 1

double gauss_ch1(double(*f)(double),int n)
{
	double result,fsum,cosr;
	int i;
	for (i=1,result=0.0;i<=n;i++)
	{
		cosr=cos(((2*i-1)*pi)/(2*n));
		fsum=(*f)(cosr);
		result+=fsum;
	}
	result=result*pi/n;
	return result;
}


double gauss_ch2(double(*f)(double),int n)
{
	double cosr,sinr,fsum,result;
	int i;
	for(i=1,result=0;i<=n;i++)
	{
		sinr=(sin((i*pi)/(n+1)));
		sinr=sinr*sinr;
		cosr=cos((i*pi)/(n+1));
		fsum=(*f)(cosr)*sinr;
		result+=fsum;
	}
	result=result*pi/(n+1);
	return result;
}


double * comp_trep(double(*f)(double),double a,double b,double epx)
{
	int i;
	int itermax=10000;//最大迭代次数
	int iter=0;
	double ep;//精度
	double n=1;
	double h=(b-a)/2;
	double Tn=h*((*f)(a)+(*f)(b));
	double T2n=0;
	double result[2];
	while((iter<10) && (ep<epx))
	{
		double sumf=0;
		for(i=1;i<=n;i++)
		{
			sumf+=(*f)(a+(2*i-1)*h);
		}
		T2n=Tn/2+h*sumf;
		ep=fabs(T2n-Tn);
		Tn=T2n;
		n*=2;
		h/=2;
		iter+=1;
	}
	result[0]=T2n;
	result[1]=ep;
	return result;

}



double * romberg(double (*f)(double),double a, double b,double eps)
{
    int m, n,i,k;//m控制迭代次数, 而n控制复化梯形积分的分点数. n=2^m
    double h, x;
    double s, q;
    double ep; //精度要求
    double y[10000];
    double p;//p总是指示待计算元素的前一个元素(同一行)
	double result[2];

    //迭代初值
    h = b - a;
    y[0] = h*((*f)(a) + (*f)(b))/2.0;
    m = 1;
    n = 1;
    ep = eps + 1.0;
    while ((ep >= eps) && (m < 10))
    {
        p = 0.0;
        for (i=0; i<n; i++)
        {
            x = a + (i+0.5)*h;
            p = p + (*f)(x);
        }
        p = (y[0] + h*p)/2.0;
        s = 1.0;
        for (k=1; k<=m; k++)
        {
            s = 4.0*s;
            q = (s*p - y[k-1])/(s - 1.0);
            y[k-1] = p;
            p = q;
        }

        ep = fabs(q - y[m-1]);
        m = m + 1;
        y[m-1] = q;
        n = n + n; h = h/2.0;
    }

    result[0]=q;
	result[1]=ep;
	return result;

}

double test(double x)
{//验证四种方法正确性的第一个函数f(x)
	return 2*x;
}

double test2(double x)
{//比较时间和误差的第二个函数f(x)
	double ex,sqrx,result;
	ex=exp(x);
	sqrx=sqrt(1-x*x);
	result=ex*sqrx;
	return result;
}

void main()
{
	double sum1,sum2;
	double *sum3;
	double *sum4;
	double ep3,ep4,time2,time3,time4;
	clock_t start,finish;
	double (*p)();
	double (*p2)();
	p=test;
	p2=test2;

	sum1=gauss_ch1(*p,10000);
	printf("第一种方法积分结果: %f\n",sum1);
	sum2=gauss_ch2(*p,10000);
	printf("第二种方法积分结果: %f\n",sum2);
	sum3=comp_trep(*p,0,1,0.000001);
	printf("第三种方法积分结果: %f\n",sum3[0]);
	sum4=romberg(*p,0,1,0.000001);
	printf("第四种方法积分结果: %f\n",sum4[0]);

	printf("----------------------------------------------------------");
	printf("\n");

	start=clock();
	sum2=gauss_ch2(*p2,10000);
	finish=clock();
	time2=finish-start;
	printf("GaussII积分结果是: %f\t 计算时间是: %f\n",sum2,time2);

	start=clock();
	sum3=comp_trep(*p2,-1,1,0.00001);
	finish=clock();
	time3=finish-start;
	printf("逐次减半复化梯形公式积分结果是: %f\t 计算时间是: %f\t 误差是: %f\n",sum3[0],time3,sum3[1]);

	start=clock();
	sum4=romberg(*p2,-1,1,0.00001);
	finish=clock();
	time4=(finish-start)*1000;

	printf("龙贝格公式积分结果是: %f\t 计算时间是: %f\t 误差是: %f\n",sum4[0],time4,sum4[1]);



}
