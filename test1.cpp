#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <algorithm>

using namespace std;

#define MAX 50

int main() {
	vector<int> iv(MAX,0);
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;
	iv.push_back(1);
	iv.shrink_to_fit();
	cout << "size = " << iv.size() << endl;
	cout << "capacity = " << iv.capacity() << endl;
	return 0;
}
