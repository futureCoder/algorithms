class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */
    bool isMatch(const char *s, const char *p) {
        int start = 0, pstart = 0, pend = 0;
        bool bFind = true;
        for(pend != p.size()) {
        	while(pend < p.size() && p[pend] != '*')
        		++pend;
        	int idx = kmp(s.substr(start, s.size() - start), pattern.substr());
        	if(pstart == 0 && idx != 0)
        		return false;
        	if(pend == p.size() && idx != s.size() - (pend - pstart))
        		return false;
        	if(!(bFind = idx == -1 ? false : true))
        		return false;
        	start = start + (pend - pstart);
        }
    }
    void makeNext(const string &pattern, vector<int>& next) {
    	int k = 0;
    	next[0] = 0;
    	for(int i = 1; i < pattern.size(); ++i) {
    		while(k > 0 && (pattern[i] != '?' && pattern[k] != '?' && pattern[i] != pattern[k]))
    			k = next[k - 1];
    		if(pattern[i] == '?' || pattern[k] == '?' || pattern[i] == pattern[k])
    			++k;
    		next[i] = k;
    	}
    	return ;
    }
    int kmp(const string &s, const string &pattern) {
    	vector<int> next(pattern.size());
    	makeNext(pattern, next);
    	int k = 0;
    	for(int i = 0; i < pattern.size(); ++i) {
    		while(k > 0 && pattern[k] != '?' && s[i] != pattern[k])
    			k = next[k - 1];
    		if(pattern[k] == '?' || s[i] == pattern[k])
    			++k;
    		if(k == pattern.size())
    			return i - k;
    	}
    	return -1;
    }
};