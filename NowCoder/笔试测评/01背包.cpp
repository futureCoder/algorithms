#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		vector<int> diamond(m), damage(m);
		for (int i = 0; i < m; ++i) {
			cin >> diamond[i] >> damage[i];
		}
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i < m + 1; ++i) {
			for (int j = 1; j < n + 1; ++j) {
				if (diamond[i - 1] <= j) {
					dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - diamond[i - 1]] + damage[i - 1]);
				}
				else
					dp[i][j] = dp[i - 1][j];
			}
		}
		vector<int> flag(m);
		for (int i = m; i > 0; --i) {
			if (dp[i][n] > dp[i - 1][n]) {
				flag[i - 1] = 1;
				n -= diamond[i - 1];
			}
		}
		int ret = 0;
		for (int i = 0; i < m; ++i)
			if (flag[i] == 1)
				ret += damage[i];
		cout << ret << endl;
	}
}