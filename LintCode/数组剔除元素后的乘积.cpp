class Solution {
public:
    /**
     * @param A: Given an integers array A
     * @return: A long long array B and B[i]= A[0] * ... * A[i-1] * A[i+1] * ... * A[n-1]
     */
    vector<long long> productExcludeItself(vector<int> &nums) {
        vector<long long> ret(nums.size(), 1);
    	if(nums.empty())
    		return ret;
    	int len = nums.size();
        long long tmp = nums[0];
        for(int i = 1; i < len; ++i) {
        	ret[i] *= tmp;
        	tmp *= nums[i];
        }
        tmp = nums[len - 1];
        for(int i = len - 2; i >= 0; --i) {
        	ret[i] *= tmp;
        	tmp *= nums[i];
        }
        return ret;
    }
};