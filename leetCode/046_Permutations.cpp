class Solution {
public:
	void permute(vector<int>& nums, int start, int end, vector<vector<int>>& ret) {
		if(start == end) {
			ret.push_bacstart(nums);
			return;
		}
		for(int i = start; i < end; ++i) {
			swap(nums[i], nums[start]);
			permute(nums, start + 1, end, ret);
			swap(nums[i], nums[start]);
		}
	}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ret;
        permute(nums, 0, nums.size(), ret);
        return ret;
    }
};