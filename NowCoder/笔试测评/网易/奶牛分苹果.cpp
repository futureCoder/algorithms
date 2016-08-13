#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

int func(vector<int> &vec, int sum, int n) {
	if(0 != (sum % n))
		return -1;
	int target = sum / n;
	sort(vec.begin(), vec.end());
	int start = 0, end = vec.size() - 1;
	int count = 0;
	while(start < end && vec[end] != target && vec[start] != target) {
		int tmp = count;
		while(vec[end] > target) {
			vec[end] -= 2;
			++count;
		}
		if(vec[end] < target)
			return -1;
		--end;
		while(tmp < count) {
			while(tmp < count && vec[start] < target) {
				vec[start] += 2;
				++tmp;
			}
			if(vec[start] > target)
				return -1;
			else if(vec[start] == target)
				++start;
		}
	}
	return count;
}

int main() {
	int n;
	while(cin >> n) {
		vector<int> vec(n);
		int sum = 0;
		for(int i = 0; i < n; ++i) {
			cin >> vec[i];
			sum += vec[i];
		}
        if(n < 2) {
            cout << 0 << endl;
            continue;
        }
		cout << func(vec, sum, n) << endl;
	}
}