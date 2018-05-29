/*
给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。
说明：本题中，我们将空字符串定义为有效的回文串。
示例 1:
输入: "A man, a plan, a canal: Panama"
输出: true

示例 2:
输入: "race a car"
输出: false
*/
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    bool isPalindrome(string s) {
        auto isValidInput = [](const char& ch) -> bool
        {
            if(('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('0' <= ch && ch <= '9'))
                return true;
            return false;
        };
        auto toLower = [](const char &ch) -> const char {
            if('A' <= ch && ch <= 'Z')
                return ch - 'A' + 'a';
            return ch;
        };
        int i = 0, j = s.size() - 1;
        while(i <= j)
        {
            while(!isValidInput(s[i])) ++i;
            while(!isValidInput(s[j])) --j;
            if(i >= j)
                break;
            if(toLower(s[i]) != toLower(s[j]))
                return false;
            ++i, --j;
        }
        return true;
    }
};