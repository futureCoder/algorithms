#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;
int result[50];
void init() {
    result[0] = 0;
    result[1] = 1;
    for(int i = 2; i < 50; ++i) 
        result[i] = result[i - 1] + result[i - 2];
    result[1] = 0;
}


int main() {
    int n;
    init();
    while(~scanf("%d", &n)) {
        while(n--) {
            int i;
            scanf("%d",&i);
            printf("%d\n",result[i]);
        }
    }
}