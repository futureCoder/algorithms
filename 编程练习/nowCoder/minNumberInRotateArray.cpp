#include <stdio.h>
#include <vector>
#include <time.h>
using namespace std;

    double Power(double base, int exponent) {
        if(exponent == 0) return 1.0;
    double ans = 1;
        while(exponent){
            if(exponent&1){
            	ans *= base;
            }
            exponent = exponent >> 1;
            base *= base;
        }
        return ans;
    }

int main(){

	printf("%lf",Power(3.1415926,300));
}

