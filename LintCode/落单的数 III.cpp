class Solution {
public:
    /**
     * @param A : An integer array
     * @return : Two integers
     */
    vector<int> singleNumberIII(vector<int> &A) {
        int num = 0;
        for(auto i : A) {
        	num ^= i;
        }
        int digit = num ^ (num & (num - 1));
        int ret1 = 0, ret2 = 0;
        for(auto i : A) {
        	if(i & digit)
        		ret1 ^= i;
        	else
        		ret2 ^= i;
        }
        return vector<int>{ret1, ret2};
    }
};