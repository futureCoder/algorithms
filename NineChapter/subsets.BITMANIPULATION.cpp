class Solution {
public:
    /**
     * @param S: A set of numbers.
     * @return: A list of lists. All valid subsets.
     */
    vector<vector<int> > subsets(vector<int> &nums) {
        vector<vector<int>> ret;
        for (int i = 0; i < 1 << nums.size(); ++i) {
            vector<int> tmp;
            for (int j = 0; j < nums.size(); ++j) {
                if (i & 1 << j) {
                    tmp.push_back(nums[j]);
                }
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};
