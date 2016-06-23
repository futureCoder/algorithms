class Solution {
public:
	void subsets(vector<int> nums, vector<int> tmp, vector<vector<int>>& ret, int i) {
		if(i == nums.size()) {
			ret.push_back(tmp);
			return;
		}
		subsets(nums, tmp, ret, i + 1);
		tmp.push_back(nums[i]);
		subsets(nums, tmp, ret, i + 1);
		return ;
	}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ret;
        subsets(nums,vector<int>(), ret, 0);
        return ret;
    }
};