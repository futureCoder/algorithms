/*
给定一个数组，它的第 i 个元素是一支给定股票第 i 天的价格。
如果你最多只允许完成一笔交易（即买入和卖出一支股票），设计一个算法来计算你所能获取的最大利润。
注意你不能在买入股票前卖出股票。
示例 1:
输入: [7,1,5,3,6,4]
输出: 5
解释: 在第 2 天（股票价格 = 1）的时候买入，在第 5 天（股票价格 = 6）的时候卖出，最大利润 = 6-1 = 5 。
     注意利润不能是 7-1 = 6, 因为卖出价格需要大于买入价格。
示例 2:
输入: [7,6,4,3,1]
输出: 0
解释: 在这种情况下, 没有交易完成, 所以最大利润为 0。
*/
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        vector<int> buy(prices.size(), 0), sell(prices.size(), 0);
        buy[0] = -prices[0];
        for(int i = 1; i < prices.size(); ++i)
        {
            buy[i] = std::max(buy[i - 1], sell[i - 1] - prices[i]);
            sell[i] = std::max(sell[i - 1], buy[i - 1] + prices[i]);
        }
        return sell[prices.size() - 1];
    }
};