#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define MAXITERATOR 50

long long int func(double n) {
	if(n < 0)
		return 0;
	long long int k = n >> 1;
	for(int i = 0; i < MAXITERATOR; ++i) {
		k = (k * k + n) / (2 * k + 1)
	}
	return k;
}

int main() {
	double n;
	while(cin >> n) {
		cout << func(n) << endl;
	}
}