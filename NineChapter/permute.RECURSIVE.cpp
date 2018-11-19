class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: A list of permutations.
     */
    vector<vector<int> > permute(vector<int> nums) {
        vector<vector<int>> ret;
        __permute(nums, ret, 0, nums.size());
        return ret;
    }
private:
    void __permute(vector<int> &nums, vector<vector<int>> &ret, int start, int end) {
        if(start == end) {
            ret.push_back(nums);
            return;
        }
        for(int i = start; i < end; ++i) {
            swap(nums[i], nums[start]);
            __permute(nums, ret, start + 1, end);
            swap(nums[i], nums[start]);
        }
    }
};
