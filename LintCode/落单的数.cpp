class Solution {
public:
	/**
	 * @param A: Array of integers.
	 * return: The single number.
	 */
    int singleNumber(vector<int> &A) {
        int ret = 0;
        for(auto i : A) {
        	ret ^= i;
        }
        return ret;
    }
};
