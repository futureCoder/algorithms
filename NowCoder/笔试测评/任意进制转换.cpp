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

const  string maps = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

string convert(int num, int base) {
    string ret;
    if (num == 0)
        ret.append(to_string(0));
    while (0 != num) {
        int digit = num % base;
        ret.append(maps.substr(digit, 1));
        num /= base;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

int main() {
    int m, n;
    while (~scanf("%d%d", &m, &n)) {
        if (m >= 0)
            cout << convert(m, n) << endl;
        else
            cout << "-" << convert(abs(m), n) << endl;
    }
}