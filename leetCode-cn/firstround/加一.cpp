/*
给定一个非负整数组成的非空数组，在该数的基础上加一，返回一个新的数组。
最高位数字存放在数组的首位， 数组中每个元素只存储一个数字。
你可以假设除了整数 0 之外，这个整数不会以零开头。

示例 1:
输入: [1,2,3]
输出: [1,2,4]
解释: 输入数组表示数字 123。

示例 2:
输入: [4,3,2,1]
输出: [4,3,2,2]
解释: 输入数组表示数字 4321。
 */
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int cy = 1;
        for(int i = digits.size() - 1; i >= 0; --i)
        {
            digits[i] += cy;
            cy = digits / 10;
            if(0 == cy)
                return digits;
            digits[i] %= 10;
        }
        if(cy)
        {
            digits.insert(digits.begin(), cy);
        }
        return digits;
    }
};