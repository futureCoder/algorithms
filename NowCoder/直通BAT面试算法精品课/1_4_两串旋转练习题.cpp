class Rotation {
public:
    void makeNext(const string &pattern, vector<int>& next) {
        int len = pattern.size();
        int k = 0;
        next[k] = 0;
        for(int i = 1; i < len; ++i) {
        	while(k > 0 && pattern[i] != pattern[k])
                k = next[k - 1];
            if(pattern[i] == pattern[k])
                ++k;
            next[i] = k;
        }
    }
    int kmp(const string &str, const string &pattern) {
        vector<int> next(pattern.size());
        makeNext(pattern, next);
        int k = 0;
        for(int i = 0; i < str.size(); ++i) {
            while(k > 0 && str[i] != pattern[k])
                k = next[k - 1];
            if(str[i] == pattern[k])
                ++k;
            if(k == pattern.size())
                return i - k + 1;
        }
        return -1;
    }
    bool chkRotation(string A, int lena, string B, int lenb) {
        if(lena != lenb)
            return false;
        if(kmp(A + A, B) == -1)
            return false;
        return true;
    }
};