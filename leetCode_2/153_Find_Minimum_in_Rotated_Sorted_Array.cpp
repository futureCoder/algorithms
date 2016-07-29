class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums.empty())
            return 0;
        int len = nums.size();
        int start = 0, end = len;
        while(start < end) {
        	int mid = start + (end - start) / 2;
        	if((mid - 1 >= 0 && nums[mid - 1] > nums[mid]) || mid == 0)
        		return nums[mid];
        	else if(nums[start] > nums[mid])  end = mid;
        	else if(nums[mid] > nums[end - 1]) start = mid + 1;
        	else end = mid;
        }
        return nums[0];
    }
};