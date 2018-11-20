/**
 * Given a string, find the length of the longest substring without repeating characters.
 * Examples:
 * Given "abcabcbb", the answer is "abc", which the length is 3.
 * Given "bbbbb", the answer is "b", with the length of 1.
 * Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0, len = 0;
        std::map<char, int> appearMap;
        for(int idx = 0; idx < s.length(); ++idx)
        {
            auto iter = appearMap.find(s[idx]);
            if(iter == appearMap.end())
            {
                //has not appear
                ++len;
                appearMap.insert(std::make_pair(s[idx], idx));
            }
            else
            {
                idx = iter->second;
                appearMap.clear();
                len = 0;
            }
            ret = std::max(ret, len);
        }
        return ret;
    }
};