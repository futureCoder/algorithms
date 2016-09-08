#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string getLuckeyNum(int bit, unsigned long long k) {
	string ret;
	if(k <= 0)
		return ret;
	int n = bit;
	--k;
	while (n-- > 0) {
		int tmp = k & 0x1;
		if (tmp == 0)
			ret.append("4");
		else
			ret.append("7");
		k = k >> 1;
	}
	if(ret.size() != 0)
		reverse(ret.begin(), ret.end());
	return ret;
}

string getKthLuckeyNumBinary(unsigned long long k) {
	int bit = 1;
	int curBitNum = 2;
	while (k > curBitNum) {
		k -= curBitNum;
		curBitNum = curBitNum << 1;
		++bit;
	}
	return getLuckeyNum(bit, k);
}

int main() {
	int n;
	while(cin >> n) {
		while(n--) {
			unsigned long long k;
			cin >> k;
			if(k <= 0)
				continue;
            string tmp = getKthLuckeyNumBinary(k);
			cout << tmp << endl;
		}
	}
    return 0;
}
