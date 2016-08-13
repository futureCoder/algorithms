class Solution {
public:
    /*
     * @param a, b, n: 32bit integers
     * @return: An integer
     */
    int fastPower(int a, int b, int n) {
    	if(0 == n)
    		return 1 % b;
    	if(1 == n)
    		return a % b;
    	int res = fastPower(a, b, n >> 1);
    	res = (res * res) % b;
    	if(n & 1)
    		res = (res * a) % b;
    	return res;
    }
};