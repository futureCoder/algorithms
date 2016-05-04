class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int begin = 0,end = nums.size();
        while(begin<end)
        {
        	const int mid = begin + (end - begin)/2;
    		if(target == nums[mid]) return true;
    		if(nums[begin]<=nums[mid])	//未过半
    		{
    		    if(nums[begin]==nums[mid])
    		    {
    		        ++begin;
    		        continue;
    		    }
    			if(nums[begin]<=target && target<nums[mid]) end = mid;
    			else begin = mid + 1;
    		}
    		else
    		{
    			if(nums[mid]<target && target<=nums[end-1]) begin = mid + 1;
    			else end = mid;
    		}
        }
        return false;
    }
};