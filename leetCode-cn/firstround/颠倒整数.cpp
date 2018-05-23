/*
给定一个 32 位有符号整数，将整数中的数字进行反转。
示例 1:
输入: 123
输出: 321

示例 2:
输入: -123
输出: -321

示例 3:
输入: 120
输出: 21
注意:
假设我们的环境只能存储 32 位有符号整数，其数值范围是 [−2^31,  2^31 − 1]。根据这个假设，如果反转后的整数溢出，则返回 0。
*/
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        int ret = 0;
        bool neg = x < 0 ? true : false;
        x = x * (neg ? -1 : 1);
        while (0 != x)
        {
            if (ret > (INT_MAX / 10))
                return 0;
            if (ret == (INT_MAX / 10) && (x % 10) > (INT_MAX % 10))
                return 0;
            ret *= 10;
            ret += x % 10;
            x /= 10;
        }
        return ret * (neg ? -1 : 1);
    }
};