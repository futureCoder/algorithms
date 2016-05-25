class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if(nums.empty()) return false;
        int len = nums.size();
        for(int i = 0; i < len - k - 1; ++i)
        {
        	for(int j = i + 1; j < len; ++j)
        		if(abs(nums[i] - nums[j]) <= t && j - i <= k)
        			return true;
        }
        return false;
    }
};