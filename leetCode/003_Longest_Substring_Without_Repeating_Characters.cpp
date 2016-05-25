class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int alphabet[256];
        memset(alphabet, -1, sizeof(alphabet));
        int index = -1, ret = 0;
        for(int i = 0; i < s.size(); ++i)
        {
        	if(alphabet[s[i]] > index)
        	{
        		index = alphabet[s[i]];
        	}
        	if(ret < i - index)
        	{
        		ret = i - index;
        	}
        	alphabet[s[i]] = i;
        }
        return ret;
    }
};