#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

void makeNext(const string &pattern, vector<int> &next) {
	int k = 0, len = pattern.size();
	next[k] = 0;

	for (int i = 1; i < len; ++i) {
		while (k > 0 && pattern[i] != pattern[k])
			k = next[k - 1];
		if (pattern[i] == pattern[k])
			++k;
		next[i] = k;
	}
}

int kmp(const string &str, const string &pattern) {
	int lenStr = str.size(), lenPatt = pattern.size();
	if (lenPatt == 0)
		return -1;
	vector<int> next(lenPatt, 0);
	makeNext(pattern, next);
	int k = 0;
	for (int i = 0; i < lenStr; ++i) {
		while (k > 0 && str[i] != pattern[k])
			k = next[k - 1];
		if (str[i] == pattern[k])
			++k;
		if (k == lenPatt)
			return i - k + 1;
	}
	return -1;
}
int strStr(string haystack, string needle) {
	return kmp(haystack, needle);
}

int main() {
	string s;
	string one;
	string two;
	while (cin >> s >> one >> two) {
		int lens = s.size(), len1 = one.size(), len2 = two.size();
		bool forward = false, backward = false;
		int start = 0;
		if ((start = (strStr(s, one))) != -1) {
			start += len1;
			if ((start = (strStr(s.substr(start, lens - start), two))) != -1)
				forward = true;
		}
		start = 0;
		reverse(s.begin(), s.end());
		if ((start = (strStr(s, one))) != -1) {
			start += len1;
			if ((start = strStr(s.substr(start, lens - start), two)) != -1)
				backward = true;
		}
		if (forward && backward)
			printf("both\n");
		else if (forward)
			printf("forward\n");
		else if (backward)
			printf("backward\n");
		else printf("invalid\n");
	}
}