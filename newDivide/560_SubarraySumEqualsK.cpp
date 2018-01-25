/**
 * Given an array of integers and an integer k, you need to find the total number of continuous subarrays whose sum equals to k.
 * Example 1:
 * Input:nums = [1,1,1], k = 2
 * Output: 2
 * Note:
 * The length of the array is in range [1, 20,000].
 * The range of numbers in the array is [-1000, 1000] and the range of the integer k is [-1e7, 1e7].
 */
#include "inc\stdafx.h"
#include "inc\leetcode.h"

namespace Solution {
    int subarraySum(vector<int>& nums, int k) {
        if(nums.empty())
            return 0;
        vector<int> sum(nums.size(), 0);
        sum[0] = nums[0];
        for(int i = 1; i < nums.size(); ++i)
            sum[i] = nums[i] + sum[i - 1];
        int ret = 0;
        for(int i = 0; i < nums.size(); ++i)
        {
            for(int j = i; j < nums.size(); ++j)
            {
                if(k == sum[j] - sum[i] + nums[i])
                    ++ret;
            }
        }
        return ret;
    }
};