#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <iomanip>

using namespace std;

vector<int> rebuild(vector<int> myvec, int len, int remain) {
	int curIdx = len;
	while(remain != 0 && curIdx < myvec.size()) {
		for(int i = 0; i < len; ++i) {
			if(myvec[i] != 0)
				continue;
			if(myvec[curIdx] != 0) {
				myvec[i] = myvec[curIdx];
				--remain;
			}
			++curIdx;
		}
	}
	return vector<int>(myvec.begin(), myvec.begin() + len);
}

int main() {
	int T;
	while(cin >> T) {
		while(T--) {
			int n;
			cin >> n;
			vector<int> myvec(2 * n, 0);
			int val = 0;
			for(int i = 1; i < myvec.size(); i += 2)
				myvec[i] = ++val;
			int remain = 2 * n - val;
			vector<int> ret = rebuild(myvec, n, remain);
			for(int i = 0; i < n; ++i) {
				char c = (i == n - 1) ? '\n' : ' ';
				cout << ret[i] << c;
			}
		}
	}
}


