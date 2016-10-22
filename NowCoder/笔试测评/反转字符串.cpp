#include <iostream>
#include <algorithm>
#include <cstring>
#include <cstdio>
#include <sstream>
#include <string>
#include <map>
#include <vector>
#include <cmath>
#include <queue>
using namespace std;

void reverseWord(string& str) {
    int start = 0, end = str.size();
    reverse(str.begin(), str.end());
    while(start < end) {
        int idx = start;
        while(idx < end && str[idx] != ' ')
            ++idx;
        reverse(str.begin() + start, str.begin() + idx);
        start = idx + 1;
    }
}

int main() {
    string str;
    while(cin >> str) {
        reverseWord(str);
        cout << str << endl;
    }
}