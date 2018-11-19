/**
 * Given an array of integers, return indices of the two numbers such that they add up to a specific target.
 * You may assume that each input would have exactly one solution, and you may not use the same element twice.
 * Example:
 * Given nums = [2, 7, 11, 15], target = 9,
 * Because nums[0] + nums[1] = 2 + 7 = 9,
 * return [0, 1].
 * [-1,-2,-3,-4,-5] -8 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::map<int, int> neededNumMap;
        std::vector<int> ret;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto iter = neededNumMap.find(target - nums[i]);
            if(iter == neededNumMap.end())
            {
                neededNumMap.insert(std::make_pair(nums[i], i));
            }
            else
            {
                ret.push_back(iter->second);
                ret.push_back(i);
                return ret;
            }
        }
        return ret;
    }
};