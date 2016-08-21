class Solution {
public:
    /**
     * @param n: An integer
     * @return: An integer
     */
    int climbStairs(int n) {
    	if(n < 2)
    		return 1;
        int a = 2, b = 1, tmp;
        for(int i = 2; i < n; ++i) {
        	tmp = a;
        	a = a + b;
        	b = tmp;
        }
        return a;
    }
};
