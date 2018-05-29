/*
实现 strStr() 函数。
给定一个 haystack 字符串和一个 needle 字符串，在 haystack 字符串中找出 needle 字符串出现的第一个位置 (从0开始)。如果不存在，则返回  -1。
示例 1:
输入: haystack = "hello", needle = "ll"
输出: 2

示例 2:
输入: haystack = "aaaaa", needle = "bba"
输出: -1
说明:
当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr() 以及 Java的 indexOf() 定义相符。
*/
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int strStr(string haystack, string needle) {
        if(0 == needle.size())
            return 0;
        if(0 == haystack.size())
            return -1;
        return kmp(haystack, needle);
    }
    void makeNext(string needle, vector<int> &next)
    {
        int k = -1;
        for (int i = 1; i < needle.size(); ++i)
        {
            while (k > -1 && needle[k + 1] != needle[i])
            {
                k = next[k];
            }
            if (needle[k + 1] == needle[i])
            {
                ++k;
            }
            next[i] = k;
        }
    }

    int kmp(string haystack, string needle)
    {
        vector<int> next(needle.size(), -1);
        makeNext(needle, next);
        int k = -1;
        for (int i = 0; i < haystack.size(); ++i)
        {
            while (k > -1 && needle[k + 1] != haystack[i])
            {
                k = next[k];
            }
            if (needle[k + 1] == haystack[i])
            {
                ++k;
            }
            if (k == needle.size() - 1)
                return i - k;
        }
        return -1;
    }
};