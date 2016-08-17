class Solution {
public:
    int strStr(string haystack, string needle) {
        return kmp(haystack, needle);
    }
	void makeNext(const string &pattern, vector<int> &next) {
		int k = 0, len = pattern.size();
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
		int lenStr = str.size(), lenPatt = pattern.size();
		vector<int> next(lenPatt, 0);
		makeNext(pattern, next);
		int k = 0;
		for(int i = 0; i < lenStr; ++i) {
			while(k > 0 && str[i] != pattern[k])
				k = next[k - 1];
			if(str[i] == pattern[k])
				++k;
			if(k == lenPatt)
				return i - k + 1;
		}
		return -1;
	}
};
