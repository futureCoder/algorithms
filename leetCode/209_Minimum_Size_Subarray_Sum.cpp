class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) { //滑动窗口
        int start = 0, end = 0, len = nums.size(), ret = nums.size(), sum = 0;
        while(end < len && ret != 1) {
        	do {
        		sum += nums[end++];
        	} while(end < len && sum < s);
        	if(sum < s)
        		return 0;
        	while(start < end && sum - nums[start] >= s) {
        		sum -= nums[start++];
        	}
        	ret = min(ret, end - start);
        }
        return ret;
    }
};