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

const vector<string> zimubiao = { "ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE" };

void deleteNumInMap(map<char, int>& alphabeta, int num, string& nums) {
	char ch;
	switch (num) {
	case 0: ch = 'Z'; break;
	case 1: ch = 'O'; break;
	case 2: ch = 'W'; break;
	case 3: ch = 'R'; break;
	case 4: ch = 'U'; break;
	case 5: ch = 'F'; break;
	case 6: ch = 'X'; break;
	case 7: ch = 'V'; break;
	case 8: ch = 'G'; break;
	case 9: ch = 'N'; break;
	}
	int k = alphabeta[ch];
	if (k > 0) {
		for (auto i : zimubiao[num]) {
			alphabeta[i] -= k;
		}
	}
	num = (num + 10 - 8) % 10;
	for (int i = 0; i < k; ++i)
		nums.append(to_string(num));
}

int parser(map<char, int>& alphabeta, string str) {
	string nums;
	deleteNumInMap(alphabeta, 0, nums);
	deleteNumInMap(alphabeta, 2, nums);
	deleteNumInMap(alphabeta, 4, nums);
	deleteNumInMap(alphabeta, 6, nums);
	deleteNumInMap(alphabeta, 8, nums);
	deleteNumInMap(alphabeta, 1, nums);
	deleteNumInMap(alphabeta, 3, nums);
	deleteNumInMap(alphabeta, 5, nums);
	deleteNumInMap(alphabeta, 7, nums);
	deleteNumInMap(alphabeta, 9, nums);
	sort(nums.begin(), nums.end());
	return stoi(nums);
}

int main() {
	int t;
	while (~scanf("%d", &t)) {
		while (t--) {
			string str;
			map<char, int> alphabeta;
			cin >> str;
			for (auto i : str) {
				++alphabeta[i];
			}
			cout << parser(alphabeta, str) << endl;
		}
	}
}