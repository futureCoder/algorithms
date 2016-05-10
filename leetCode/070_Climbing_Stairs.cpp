class Solution {
public:
    int climbStairs(int n) {
    	if(n < 3) return 1;
        int first = 1, second = 1;
        for(int i = 3; i <= n; ++i)
        {
        	int tmp = first;
        	first += second;
        	second = tmp;
        }
        return first;
    }
};