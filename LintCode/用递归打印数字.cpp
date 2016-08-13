class Solution {
public:
    /**
     * @param n: An integer.
     * return : An array storing 1 to the largest number with n digits.
     */
    void numbersByRecursion(int weight, int n, vector<int>& ret) {
    	if(weight > n)
    		return;
    	int min = ret.empty() ? 1 : ret.back() + 1;
    	int max = 10 * min;
    	for(int i = min; i < max; ++i) 
    		ret.push_back(i);
    	numbersByRecursion(weight + 1, n, ret);
    }
    vector<int> numbersByRecursion(int n) {
        vector<int> ret;
        numbersByRecursion(1, n, ret);
        return ret;
    }
};