class Solution {
public:
    /*
     * @param n an integer
     * @return the nth prime number as description.
     */
	int minUgly(int a, int b, int c) {
		a = min(a,b);
		a = min(a,c);
		return a;
	}
	int nthUglyNumber(int n) {
	    if(n < 1)
	        return 0;
	    vector<int> vecUglyNumber(n);
	    vecUglyNumber[0] = 1;
	    vector<int>::iterator itertor2, itertor3, itertor5, itertorNextUgly;
	    itertor2 = itertor3 = itertor5 = vecUglyNumber.begin();
	    itertorNextUgly = itertor2 + 1;
	    while(itertorNextUgly != vecUglyNumber.end()) {
	    	int nextUgly = minUgly(*itertor2 * 2, *itertor3 * 3, *itertor5 * 5);
	    	*itertorNextUgly = nextUgly;
	    	while(*itertor2 * 2 <= *itertorNextUgly)
	    		++itertor2;
	    	while(*itertor3 * 3 <= *itertorNextUgly)
	    		++itertor3;
	    	while(*itertor5 * 5 <= *itertorNextUgly)
	    		++itertor5;
	    	++itertorNextUgly;
	    }
	    return vecUglyNumber[n - 1];
	}
};