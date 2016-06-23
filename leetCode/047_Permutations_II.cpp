class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        vector<vector<int>> ret;
        while(true) {
        	ret.push_back(nums);
        	int i = len - 2, j = len - 1;
        	while(i > 0 && nums[i] >= nums[i + 1]) --i;
        	while(j > 0 && nums[i] >= nums[j]) --j;
        	if(j == 0) break;
        	swap(nums[i], nums[j]);
        	j = len - 1;
        	++i;
        	while(i < j)
        		swap(nums[i], nums[j]);
        }
        return ret;
    }
};