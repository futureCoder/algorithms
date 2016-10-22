#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int countDight(unsigned int n) {
    int cnt = 0;
    while(0 != n) {
        n &= (n - 1);
        ++cnt;
    }
    return cnt;
}

int main() {
    int l, r, m;
    while(~scanf("%d%d%d", &l, &r, &m)) {
        int cnt = 0;
        for(int i = l; i <= r; ++i) {
            if(countDight(i) == m)
                ++cnt;
        }
        if(cnt == 0)
            printf("-1\n");
        else
            printf("%d\n", cnt);
    }
}