class Solution {
public:    
    /**
     * @param nums: A list of integers
     * @return: A integer indicate the sum of max subarray
     */
    int maxSubArray(vector<int> nums) {
    	if(nums.empty())
    		return 0;
    	int sum = 0;
    	int ret = nums[0];
    	for(const auto &i : nums) {
    		sum += i;
    		ret = std::max(ret, sum);
    		if(sum < 0)
    			sum = 0;
    	}
    	return ret;
    }
};
