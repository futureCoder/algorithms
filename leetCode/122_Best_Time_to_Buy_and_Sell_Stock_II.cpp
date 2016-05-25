class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() < 2) return 0;
        int ret = 0, tmp = 0;
        for(int i = 1; i < prices.size(); ++i)
        {
        	tmp = prices[i] - prices[i - 1];
        	if(tmp >= 0)
        	{
        		ret += tmp;
        	}
        }
        return ret;
    }
};