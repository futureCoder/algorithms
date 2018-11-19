class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
     vector<vector<int> > permute(vector<int> nums) {
     	sort(nums.begin(), nums.end());
     	vector<vector<int>> ret;
     	int size = nums.size();
     	while (true) {
     		int i = size - 2, j = size - 1;
     		ret.push_back(nums);
     		while (i > 0 && nums[i] >= nums[i + 1]) --i;
     		while (j > 0 && nums[i] >= nums[j]) --j;
     		if (j <= 0)
     			break;
     		swap(nums[i], nums[j]);
     		j = size - 1, ++i;
     		while (i < j)
     			swap(nums[i++], nums[j--]);
     	}
     	return ret;
     }
};
