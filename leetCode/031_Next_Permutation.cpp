class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size() < 2) return;
        int i = nums.size();
        while(--i > 0)
        {
        	if(nums[i - 1] >= nums[i]) continue;
        	else
        	{
        		if(i == (nums.size()-1))
        		{
        			swap(nums[i],nums[i-1]);
        			return;
        		}
        		else
        		{
        			int j = nums.size() - 1;
        			while(nums[j] <= nums[i - 1] && j > (i-1)) --j;
        			swap(nums[i-1],nums[j]);
        			reverse(nums.begin() + i, nums.end());
        			return;
        		}
        	}
        }
        reverse(nums.begin(),nums.end());
        return;
    }
};