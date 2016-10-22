#include<iostream>
#include<cmath>
using namespace std;

int main()
{
    int x, y, steps;
    cin >> x >> y >> steps;
    int distance = abs(x) + abs(y);
    bool flag;
    if(distance <= steps && ((steps - distance) % 2 == 0)) flag = true;
    else flag = false;

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}