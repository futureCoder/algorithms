/*
给定一个整数数组 nums ，找出一个序列中乘积最大的连续子序列（该序列至少包含一个数）。
示例 1:
输入: [2,3,-2,4]
输出: 6
解释: 子数组 [2,3] 有最大乘积 6。

示例 2:
输入: [-2,0,-1]
输出: 0
解释: 结果不能为 2, 因为 [-2,-1] 不是子数组。
思路：访问到每个点的时候，以该点为子序列的末尾的乘积，要么是该点本身，要么是该点乘以以前一点为末尾的序列，注意乘积负负得正，故需要记录前面的最大最小值。
*/
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(0 == nums.size())
            return 0;
        int max = nums[0], min = nums[0], ret = nums[0];
        for(int i = 1; i < nums.size(); ++i)
        {
            int n = nums[i], tmpMax = max, tmpMin = min;
            max = std::max(n, std::max(tmpMax * n, tmpMin * n));
            min = std::min(n, std::min(tmpMax * n, tmpMin * n));
            ret = std::max(ret, max);
        }
        return ret;
    }
};