class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        if(s.empty())
        	return s;
        reverse(s.begin(), s.end());
        int storeIdx = 0;
        for(int i = 0; i < s.size(); ++i) {
        	if(' ' != s[i]) {
        		if(0 != storeIdx)
        			s[storeIdx++] = ' ';
        		int j = i;
        		while(j < s.size() && s[j] != ' ')
        			s[storeIdx++] = s[j++];
        		reverse(s.begin() + storeIdx - (j - i), s.begin() + storeIdx);
        		i = j;
        	}
        }
        s.erase(s.begin() + storeIdx, s.end());
        return s;
    }
};