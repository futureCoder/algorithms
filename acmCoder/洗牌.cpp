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

void xipai(vector<int> &myvec, int n) {
	vector<int> a(myvec.begin(), myvec.begin() + n);
	vector<int> b(myvec.begin() + n, myvec.end());
	int curIdx = 0, idxA = 0, idxB = 0;
	while(curIdx < 2 * n) {
		myvec[curIdx++] = a[idxA++];
		myvec[curIdx++] = b[idxB++];
	}
}

int main() {
	int T;
	while(cin >> T) {
		while(T--) {
			int n, k;
			cin >> n >> k;
			vector<int> myvec(2 * n, 0);
			for(int i = 0; i < 2 * n; ++i)
				cin >> myvec[i];
			for(int i = 0; i < k; ++i)
				xipai(myvec, n);
			for(int i = 0; i < 2 *n; ++i) {
				char c = (i == n - 1) ? '\n' : ' ';
				cout << myvec[i] << c;
			}
		}
	}
}

