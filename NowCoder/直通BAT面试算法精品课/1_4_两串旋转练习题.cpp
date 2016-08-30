class Rotation {
public:
    void makeNext(const string &pattern, vector<int>& next) {
        int len = string.size();
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
        
    }
    bool chkRotation(string A, int lena, string B, int lenb) {
        
    }
};