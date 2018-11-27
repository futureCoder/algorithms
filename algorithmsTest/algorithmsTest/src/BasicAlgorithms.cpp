#include "BasicAlgorithms.h"

namespace Solution
{
    int binarySearch(const vector<int>& nums, int start, int end/*real end idx 's next*/, int target)
    {
        if (start >= end)
            return -1;
        int mid = start + (end - start - 1) / 2;			/*real mid idx*/
        if (nums[mid] == target)
            return mid;
        else if (target < nums[mid])
            return binarySearch(nums, start, mid, target);
        else
            return binarySearch(nums, mid + 1, end, target);
    }

    int targetSearch(const vector<int>& nums, int target) {
        return binarySearch(nums, 0, nums.size(), target);
    }
}