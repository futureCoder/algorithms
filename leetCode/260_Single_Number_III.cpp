class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int sum = 0;
        for(auto i : nums)
        	sum ^= i;
        int m = sum &(~(sum - 1));
        int a = 0, b = 0;
        for(auto i : nums)
        	if(m & i)
        		a ^= i;
        	else
        		b ^= i;
        return vector<int>{a,b};
    }
};