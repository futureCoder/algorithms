#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <list>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

int randomRange(int start, int end) {
	return (rand() % (end - start + 1) + start);
}

typedef struct node {
	int val;
	struct node *next;
}ListNode;

int partition(vector<int>& nums, int start, int end) {
	int target = randomRange(start, end);
	swap(nums[start], nums[target]);
	int tmp = nums[start];
	while(start < end) {
		while(start < end && nums[end] > tmp) --end;
		nums[start] = nums[end];
		while(start < end && nums[start] <= tmp) ++start;
		nums[end] = nums[start];
	}
	nums[start] = tmp;
	return target;
}
void quickSort1(vector<int>& nums, int start, int end) {
	if(start >= end)
		return ;
	int target = partition(nums, start, end);
	quickSort1(nums, start, target - 1);
	quickSort1(nums, target + 1, end);
}

void heapAdjust(vector<int> &nums, int i, int len) {
	int child, tmp;
	for(tmp = nums[i]; 2 * i + 1 < len; i = child) {
		child = 2 * i + 1;
		if(child + 1 < len && nums[child + 1] > nums[child]) ++child;
		if(tmp < nums[child]) {
			nums[i] = nums[child];
			nums[child] = tmp;
		}
		else break;
	}
}

void heapSort(vector<int>& nums) {
	int len = nums.size();
	for(int i = (len - 1) / 2;i >= 0; --i)
		heapAdjust(nums, i, len);
	for(int i = len - 1; i >= 0; --i) {
		swap(nums[0], nums[i]);
		heapAdjust(nums, 0, i);
	}
}

int main() {
	time_t t;
	srand((unsigned int)time(&t));
	vector<int> nums;
	for(int i = 0; i < 100; ++i) {
		nums.push_back(randomRange(0, 100));
	}
	for(auto num : nums)
		cout << num << " ";
		cout<<endl;
	//quickSort1(nums, 0, nums.size() - 1);
	heapSort(nums);
	cout<<"new"<<endl;
	for(auto num : nums)
		cout << num << " ";
}
