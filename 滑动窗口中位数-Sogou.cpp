#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <cstdio>
#include <queue>

using namespace std;


vector<int> medianSlidingWindow(vector<int> inVec, int k) {
	vector<int> ret;
	priority_queue<int> maxHeap;
	priority_queue<int, vector<int>, greater<int> > minHeap;
	int median = inVec[0];
	for (int i = 1; i < k; ++i) {
		if (inVec[i] < median) {
			maxHeap.push(inVec[i]);
		}
		else {
			minHeap.push(inVec[i]);
		}
		if (maxHeap.size() > minHeap.size()) {
			minHeap.push(median);
			median = maxHeap.top();
			maxHeap.pop();
		}
		if (maxHeap.size() < minHeap.size() - 1) {
			maxHeap.push(median);
			median = minHeap.top();
			minHeap.pop();
		}
	}
	ret.push_back(median);
	int rawLen = inVec.size();
	for (int i = 0; i < rawLen; ++i) {
		inVec.push_back(inVec[i]);
	}
	for (int i = k; ret.size() != rawLen && i < inVec.size(); ++i) {
		if (inVec[i] < median) {
			maxHeap.push(inVec[i]);
		}
		else {
			minHeap.push(inVec[i]);
		}

		int old = inVec[i - k];
		if (old == median) {
			if (minHeap.size() > maxHeap.size()) {
				median = minHeap.top();
				minHeap.pop();
			}
			else {
				median = maxHeap.top();
				maxHeap.pop();
			}
		}
		else if (old < median) {
			vector<int> tmp;
			while (!maxHeap.empty()) {
				tmp.push_back(maxHeap.top());
				maxHeap.pop();
			}
			while (!tmp.empty()) {
				int val = tmp.back();
				tmp.pop_back();
				if (val != old)
					maxHeap.push(val);
			}
		}
		else {
			vector<int> tmp;
			while (!minHeap.empty()) {
				tmp.push_back(minHeap.top());
				minHeap.pop();
			}
			while (!tmp.empty()) {
				int val = tmp.back();
				tmp.pop_back();
				if (val != old)
					minHeap.push(val);
			}
		}

		while (maxHeap.size() > minHeap.size()) {
			minHeap.push(median);
			median = maxHeap.top();
			maxHeap.pop();
		}
		while (maxHeap.size() < (minHeap.size() - 1)) {
			maxHeap.push(median);
			median = minHeap.top();
			minHeap.pop();
		}
		ret.push_back(median);
	}
	return ret;
}

int main() {
	int n;
	while (scanf("%d", &n)) {
		int r;
		scanf("%d", &r);
		vector<int> nums(n);
		for (int i = 0; i < n; ++i)
			cin >> nums[i];
		while (r <= n) {
			vector<int> tmp = medianSlidingWindow(nums, r++);
			nums.swap(tmp);
		}
		if(!nums.empty())
			cout << nums.back() << endl;
	}
}