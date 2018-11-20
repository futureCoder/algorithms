class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
    	vector<vector<int>> ret;
        __subsets(nums, vector<int>(), ret, 0);
        return ret;
    }
private:
    void __subsets(const vector<int> &nums, vector<int> tmp, vector<vector<int>> &ret, int i) {
        if (i == nums.size()) {
            ret.push_back(tmp);
            return ;
        }
        __subsets(nums, tmp, ret, i + 1);
        tmp.push_back(nums[i]);
        __subsets(nums, tmp, ret, i + 1);
    }
};
