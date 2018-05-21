/*
给定一个整数数组和一个目标值，找出数组中和为目标值的两个数。
你可以假设每个输入只对应一种答案，且同样的元素不能被重复利用。
示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]
 */
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::vector<int> ret;
        std::map<int, int> myMap;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto iter = myMap.find(target - nums[i]);
            if(myMap.end() != iter)
            {
                ret.push_back(iter->second);
                ret.push_back(i);
                return ret;
            }
            myMap.insert(std::make_pair(nums[i], i));
        }
        return ret;
    }
};