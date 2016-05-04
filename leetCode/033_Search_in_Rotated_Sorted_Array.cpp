class Solution {
public:
    int search(vector<int>& nums, int target) {
        int begin = 0,end = nums.size()-1;
        int mid = (begin + end)/2;
        for(;begin<=end;mid = (begin+end)/2)
        {
            if(target==nums[mid]) return mid;
            if(end - begin>1)
            {
                if(target>nums[mid])
                {
                    if(nums[mid]>nums[end]) begin = mid;    //数组左移未过半
                    else if(target <= nums[end]) begin = mid; //过半 注意一定是<=
                    else end = mid;
    
                }
                if(target<nums[mid])
                {
                    if(nums[mid]<nums[end]) end = mid;    //数组左移过半
                    else if(target >= nums[begin]) end = mid; //未过半 注意一定是>=
                    else begin = mid;
                }
            }
            else
            {
                if(target == nums[begin]) return begin;
                if(target == nums[end]) return end;
                return -1;
            }
        }
        return -1;
    }
};