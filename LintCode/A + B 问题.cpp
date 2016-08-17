class Solution {
public:
    /*
     * @param a: The first integer
     * @param b: The second integer
     * @return: The sum of a and b
     */
    int aplusb(int a, int b) {
    	if(0 == b)
    		return a;
    	int sum, carry;
    	sum = a ^ b;
    	carry = (a & b) << 1;
    	return aplusb(sum, carry);
    }
};