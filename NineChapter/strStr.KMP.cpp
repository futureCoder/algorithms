/*
strStr
Returns the position of the first
occurrence of string target in string source,
or -1 if target is not part of source.
int strStr(String source, String target) {
//…
}
//http://lintcode.com/problem/strstr/
*/
class Solution {
public:
    /**
     * Returns a index to the first occurrence of target in source,
     * or -1  if target is not part of source.
     * @param source string to be scanned.
     * @param target string containing the sequence of characters to match.
     */
     int strStr(const char *source, const char *target) {
         if (source == NULL || target == NULL) {
             return -1;
         }
         return kmp(string(source), string(target));
     }
 private:
     void makeNext(const string target, vector<int> &next) {
     	int len = target.size();
     	if (len == 0) {
     		return;
     	}
     	next[0] = 0;
     	int k = 0;
     	for (int i = 1; i < len; ++i) {
     		while (k > 0 && target[i] != target[k]) {
     			k = next[k - 1];
     		}
     		if (target[i] == target[k]) {
     			++k;
     		}
     		next[i] = k;
     	}
     }
     int kmp(const string source, const string target) {
     	if (source.size() == 0) {
     		if (target.size() == 0) {
     			return 0;
     		}
     		else {
     			return -1;
     		}
     	}
     	if (target.size() == 0) {
     		return 0;
     	}
     	int len = source.size(), k = 0;
     	vector<int> next(target.size());
     	makeNext(target, next);
     	for (int i = 0; i < len; ++i) {
     		while (k > 0 && source[i] != target[k]) {
     			k = next[k - 1];
     		}
     		if (source[i] == target[k]) {
     			++k;
     		}
     		if (k == target.size()) {
     			return i - k + 1;
     		}
     	}
     	return -1;
     }
};
