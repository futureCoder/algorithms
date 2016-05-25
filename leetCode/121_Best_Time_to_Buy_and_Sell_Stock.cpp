class Solution {
public:
    int maxProfit(vector<int>& prices) {
    	if(prices.empty()) return 0;
        int minNum = prices[0] , ret = 0;
        for(auto i : prices)
        {
        	minNum = min(minNum, i);
        	ret = max(ret, i - minNum);
        }
        return ret;
    }
};