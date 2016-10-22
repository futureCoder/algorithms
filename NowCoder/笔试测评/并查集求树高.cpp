#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

int getDep(const vector<int>& vecUnion, int num) {
	int cnt = 0;
	int tmp;
	do {
		++cnt;
		tmp = num;
		num = vecUnion[num];
	} while (tmp != num);
	return cnt;
}

int main() {
	int n;
	while (~scanf("%d", &n)) {
		vector<int> vecUnion(1 << n, 0);
		vector<int> vecNum;
		for (int i = 0; i < n - 1; ++i) {
			int father, child;
			scanf("%d%d", &father, &child);
			vecUnion[child] = father;
			vecNum.push_back(child);
		}
		int ret = 0;
		while (!vecNum.empty()) {
			ret = max(ret, getDep(vecUnion, vecNum.back()));
			vecNum.pop_back();
		}
		cout << ret << endl;
	}
}