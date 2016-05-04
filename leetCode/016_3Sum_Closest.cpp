class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int ret = INT_MAX;
        for(int i = 0; i < nums.size() - 2; ++i)
        {
        	if(i > 0 && nums[i] == nums[i-1]) continue;
        	for(int j = i + 1, k = nums.size() - 1; j < k;)
        	{
        		int tmp = nums[i] + nums[j] + nums[k] - target;
        		if(abs(ret) > abs(tmp)) ret = tmp;
        		if(tmp < 0)
        		{
        			++j;
        			while(nums[j] == nums[j - 1] && j < k) ++j;
        		}
        		else if(tmp > 0)
        		{
        			--k;
        			while(nums[k] == nums[k + 1] && j < k) --k;
        		}
        		else return target;
        	}
        }
        return (ret + target);
    }
};