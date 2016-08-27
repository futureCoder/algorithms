class Solution {
public:
    /**
     * @param s: A string 
     * @param p: A string includes "?" and "*"
     * @return: A boolean
     */

    void makeNext(const string &pattern, vector<int>& next) {
        int k = 0;
        next[0] = 0;
        for(int i = 1; i < pattern.size(); ++i) {
            while(k > 0 && (pattern[i] != '?' && pattern[k] != '?' && pattern[i] != pattern[k]))
                k = next[k - 1];
            if(pattern[i] == pattern[k])
                ++k;
            next[i] = k;
        }
        return ;
    }
    int kmp(const string &s, const string &pattern) {
        vector<int> next(pattern.size());
        makeNext(pattern, next);
        int k = 0;
        for(int i = 0; i < s.size(); ++i) {
            while(k > 0 && pattern[k] != '?' && s[i] != pattern[k])
                k = next[k - 1];
            if(pattern[k] == '?' || s[i] == pattern[k])
                ++k;
            if(k == pattern.size())
                return i - k + 1;
        }
        return -1;
    }
    bool isMatch(const string s, const string p) {
        int start = 0, pstart = 0, pend = 0;
        while(pend < p.size()) {
            if('*' == p[pend]) {
                ++pstart;++pend;
                continue;
            }
            while(pend < p.size() && p[pend] != '*')
                ++pend;
            int idx = kmp(s.substr(start, s.size() - start), p.substr(pstart, pend - pstart));
            if(pstart == 0 && idx != 0)
                return false;
            if(pend == p.size() && idx != (s.size() - start - (pend - pstart)))
                return false;
            if(-1 == idx)
                return false;
            start += (idx + (pend - pstart));
            pstart = pend + 1;
            ++pend;
        }
        return true;
    }
    bool isMatch(const char *s, const char *p) {
        string s1{s};
        string s2{p};
        return isMatch(s1, s2);
    }
};