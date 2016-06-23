class Solution {
public:
	void permute(vector<int>& nums, int k, int m, vector<vector<int>>& ret) {
		if(k == m) {
			ret.push_back(nums);
			return;
		}
		for(int i = k; i < m; ++i) {
			swap(nums[i], nums[k]);
			permute(nums, k + 1, m, ret);
			swap(nums[i], nums[k]);
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        permute(nums, 0, nums.size(), ret);
        return ret;
    }
};