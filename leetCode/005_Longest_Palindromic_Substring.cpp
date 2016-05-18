class Solution {
public:
    string longestPalindrome(string s) {
        int len = s.size(),index = 0,slen = 1;
        bool f[len][len];
        fill_n(&f[0][0],len*len,false);
        for(int i = 0; i < len; ++i)
        {
            f[i][i] = true;
            if(i < len - 1 && s[i] == s[i + 1]) f[i][i + 1] = true;
            for(int j = 0; j < i; ++j)
            {
                if(s[j] == s[i] && f[j+1][i-1] == true) f[j][i] = true;
                if(f[j][i] == true && i - j + 1 > slen)
                {
                    slen = i - j + 1;
                    index = j;
                }
            }
        }
        string ret(s,index,slen);
        return ret;
    }
};