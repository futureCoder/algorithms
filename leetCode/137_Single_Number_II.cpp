class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ret = 0, tmp = 0;
        for(auto &i : nums)
        {
        	ret ^= i & ~tmp;
        	tmp ^= i & ~ret;
        }
        return ret;
    }
};