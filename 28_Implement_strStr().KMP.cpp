class Solution {
public:
    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }
private:
    int kmp(const string &target, const string &partten) {
        if(partten.size() == 0) return 0;
        if(target.size() == 0) return -1;
        int size = partten.size();
        vector<int> next(size, 0);
        makeNext(partten, next);
        int k = 0;
        for(int i = 0; i < target.size(); ++i) {
            while(k > 0 && target[i] != partten[k])
                k = next[k - 1];
            if(target[i] == partten[k])
                ++k;
            if(k == partten.size())
                return i - k + 1;
        }
        return -1;
    }
    void makeNext(const string &str, vector<int> &next) {
        int k = 0;
        for(int i = 1; i < str.size(); ++i) {   //注意是i = 1 而不是i = 0;
            while(k > 0 && str[i] != str[k])
                k = next[k - 1];
            if(str[i] == str[k])
                ++k;
            next[i] = k;
        }
    }
};
