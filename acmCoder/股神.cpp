#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int func(int k) {
    int val = 1, cnt = 1;
    int tmp = cnt;
    for(int i = 1; i < k; ++i) {
        if(0 == tmp) {
            --val;
            ++cnt;
            tmp = cnt;
        }
        else {
            ++val;
            --tmp;
        }
    }
    return val;
}

int main() {
    int n;
    int cnt = 0;
    int val = 1;
    while(~scanf("%d", &n)) {
        printf("%d\n", func(n));
    }
}