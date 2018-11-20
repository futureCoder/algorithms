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
     	for (int i = 0; i < strlen(source) - strlen(target) + 1; ++i) {
     		int j = 0;
     		for (; j < strlen(target); ++j) {
     			if (source[i + j] != target[j]) {
     				break;
     			}
     		}
     		if (j == strlen(target)) {
     			return i;
     		}
     	}
     	return -1;
     }
};
