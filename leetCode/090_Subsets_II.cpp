class Solution {
public:
	void subsetsWithDup(const vector<int>& nums, vector<int> tmp, vector<vector<int>>& ret, int i) {
		if(i == nums.size() && find(ret.begin(), ret.end(), tmp) == -1) {
			ret.push_back(tmp);
			return ;
		}
		subsetsWithDup(nums, tmp, ret, i + 1);
		tmp.push_back(nums[i]);
		subsetsWithDup(nums, tmp, ret, i + 1);
		tmp.pop_back();
	}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ret;
        subsetsWithDup(nums, vector<int>(), ret, 0);
        return ret;
    }
};
