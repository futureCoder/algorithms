/*
编写一个函数来查找字符串数组中的最长公共前缀。
如果不存在公共前缀，返回空字符串 ""。
示例 1:
输入: ["flower","flow","flight"]
输出: "fl"

示例 2:
输入: ["dog","racecar","car"]
输出: ""
解释: 输入不存在公共前缀。
说明:
所有输入只包含小写字母 a-z 。
*/
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        std::string ret = "";
        if(0 == strs.size())
            return ret;
        std::size_t minLen = INT_MAX;
        for(auto str : strs)
        {
            minLen = std::min(minLen, str.size());
        }
        int i = 0;
        for(; i < minLen; ++i)
        {
            bool quitFlag = false;
            for(int j = 0; j < strs.size(); ++j)
            {
                if(strs[j][i] != strs[0][i])
                {
                    quitFlag = true;
                    break;
                }
            }
            if(quitFlag)
                break;
        }
        return strs[0].substr(0, i);
    }
};