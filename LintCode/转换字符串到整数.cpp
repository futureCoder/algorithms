class Solution {
public:
    /**
     * @param str: A string
     * @return An integer
     */
    int atoi(string str) {
    	if(str.empty())
    		return 0;
        bool neg = false;
        int curIdx = 0, curSum = 0, weight = 1, len = str.size();
        while(curIdx < len && str[curIdx] == ' ')
        	++curIdx;
    	if('-' == str[curIdx] || '+' == str[curIdx]) {
    		neg = (str[curIdx] == '-');
    		++curIdx;
    	}
    	while(curIdx < len && '0' <= str[curIdx] && str[curIdx] <= '9') {
    		int curDight = str[curIdx] - '0';
    	    if(curSum > INT_MAX / 10 || (curSum == INT_MAX / 10 && curDight > INT_MAX % 10)) {
    	    	if(!neg)
    	    		return INT_MAX;
    	    	else return INT_MIN;
    	    }
    	    curSum *= 10;
    	    curSum += curDight;
    	    ++curIdx;
    	}
    	return neg ? (-1 * curSum) : curSum;
    }
};