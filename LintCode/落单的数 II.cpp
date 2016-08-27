class Solution {
public:
	/**
	 * @param A : An integer array
	 * @return : An integer 
	 */
    int singleNumberII(vector<int> &A) {
        int ret = 0, tmp = 0;
        for(auto i : A) {
        	ret = ret ^ i & ~tmp;
        	tmp = tmp ^ i & ~ret;
        }
        return ret;
    }
};