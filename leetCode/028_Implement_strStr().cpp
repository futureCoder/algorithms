class Solution {
public:
	void makeNext(const string needle,vector<int> &next) {
		int len = next.size();
		next[0] = 0;
		for(int i = 1, k = 0; i < len; ++i)
		{
			while(k > 0 && needle[i] != needle[k]) k = next[k - 1];
			if(needle[i] == needle[k]) ++k;
			next[i] = k;
		}
	}
	int kmp(string &haystack, string &needle) {
		int len = needle.size();
		if(needle.size() == 0) return 0;
		if(haystack.size() == 0) return -1;
		vector<int> next(len,0);
		makeNext(needle,next);
		for(int i = 0,j = 0; i < haystack.size(); ++i)
		{
			while(j > 0 && haystack[i] != needle[j]) j = next[j - 1];
			if(haystack[i] == needle[j]) ++j;
			if(j == len) return i - j + 1;
		}
		return -1;
	}
    int strStr(string haystack, string needle) {
        return kmp(haystack,needle);
    }
};