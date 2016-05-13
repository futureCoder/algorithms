class Solution {
public:
    bool isPalindrome(string s) {
        int pre = 0,cur = 0,len = s.size();
        while(cur < len)
        {
        	if('a' <= s[cur] && s[cur] <= 'z')
        		s[pre++] = s[cur++];
        	else if('A' <= s[cur] && s[cur] <= 'Z')
        		s[pre++] = s[cur++] - 'A' + 'a';
        	else if('0' <= s[cur] && s[cur] <= '9')
        	    s[pre++] = s[cur++];
        	else
        		++cur;
        }
        len = pre;
        for(pre = 0,cur = len - 1; pre != len;++pre,--cur)
        	if(s[pre] != s[cur]) return false;
        return true;
    }
};