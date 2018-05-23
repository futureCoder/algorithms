/*
给定一个字符串，找到它的第一个不重复的字符，并返回它的索引。如果不存在，则返回 -1。
案例:
s = "leetcode"
返回 0.
s = "loveleetcode",
返回 2.
注意事项：您可以假定该字符串只包含小写字母。
*/
static const auto __ = []()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    return nullptr;
}();
class Solution {
public:
    int firstUniqChar(string s) {
        bool isShow[26], isUniq[26];
        memset(isShow, false, sizeof(isShow));
        memset(isUniq, true, sizeof(isUniq));
        int ret = -1;
        for (auto ch : s)
        {
            int idx = ch - 'a';
            if (isShow[idx])
            {
                isUniq[idx] = false;
            }
            else
            {
                isShow[idx] = true;
            }
        }
        for (auto iter = s.begin(); iter != s.end(); ++iter)
        {
            int idx = *iter - 'a';
            if (isShow[idx] && isUniq[idx])
            {
                ret = iter - s.begin();
                break;
            }
        }
        return ret;
    }
};