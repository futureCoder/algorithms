class Solution {
public:
	int candy(const vector<int>& ratings) {
		vector<int> nums(ratings.size());
		int sum = 0;
		for (int i = 0; i < ratings.size(); ++i)
			sum += solve(ratings, nums, i);
		return sum;
	}
	int solve(const vector<int>& ratings, vector<int>& nums, int i) {
		if (nums[i] == 0) {
			nums[i] = 1;
			if (i > 0 && ratings[i] > ratings[i - 1])
				nums[i] = max(nums[i], solve(ratings, nums, i - 1) + 1);
			if (i < ratings.size() - 1 && ratings[i] > ratings[i + 1])
				nums[i] = max(nums[i], solve(ratings, nums, i + 1) + 1);
		}
		return nums[i];
	}
};