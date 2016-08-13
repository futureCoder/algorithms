class Solution {
public:
    /**
     * @param nums: a vector of integers
     * @return: nothing
     */
    void partitionArray(vector<int> &nums) {
        int idx = 0, cur = 0;
        auto isOdd = [&](int k) {
        	if(k & 1)
        		return true;
        	return false;
        };
        while(cur < nums.size()) {
        	while(cur < nums.size() && !isOdd(nums[cur]))
        		++cur;
        	swap(nums[idx++], nums[cur++]);
        }
    }
};