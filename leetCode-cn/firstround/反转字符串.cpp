/*
请编写一个函数，其功能是将输入的字符串反转过来。
示例：
输入：s = "hello"
返回："olleh"
 */
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string reverseString(string s) {
        std::reverse(s.begin(), s.end());
        return s;
    }
};