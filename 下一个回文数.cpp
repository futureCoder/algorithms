#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <cstdio>
#include <queue>

using namespace std;

bool isAll9(int num) {
	bool ret = true;
	while (num != 0) {
		if (num % 10 != 9) {
			ret = false;
			break;
		}
		num /= 10;
	}
	return ret;
}

int getAns(int num) {
	if (num <= 0)
		return 0;
	if (isAll9(num)) {
		return num + 2;
	}
	if (num < 10) {
		return num + 1;
	}
	string numStr = to_string(num);
	int len = numStr.length();
	bool odd = false;
	if (len & 1 == 1)
		odd = true;
	string leftStr, rightStr, reverseLeftStr;
	int leftNum, rightNum, reserveLeftNum;

	if (len > 1) {
		leftStr.append(numStr, 0, len >> 1);
		if (odd)
			rightStr.append(numStr, (len >> 1) + 1, len >> 1);
		else
			rightStr.append(numStr, len >> 1, len >> 1);
		reverseLeftStr = leftStr;
		reverse(reverseLeftStr.begin(), reverseLeftStr.end());
		leftNum = stoi(leftStr);
		rightNum = stoi(rightStr);
		reserveLeftNum = stoi(reverseLeftStr);
	}
	int resultNum;
	string resultString;

	if (odd) {
		char ch = numStr.at(len >> 1);
		int mid = ch - '0';
		if (reserveLeftNum <= rightNum) {
			if (mid < 9) {
				++ch;
			}
			else {
				ch = '0';
				leftNum++;
				leftStr = to_string(leftNum);
				reverseLeftStr = leftStr;
				reverse(reverseLeftStr.begin(), reverseLeftStr.end());
			}
		}
		resultString = leftStr;
		resultString.append(1, ch);
		resultString += reverseLeftStr;
		resultNum = stoi(resultString);
	}
	if (!odd) {
		if (reserveLeftNum <= rightNum) {
			++leftNum;
			leftStr = to_string(leftNum);
			reverseLeftStr = leftStr;
			reverse(reverseLeftStr.begin(), reverseLeftStr.end());
		}
		resultString = leftStr;
		resultString += reverseLeftStr;
		resultNum = stoi(resultString);
	}
	return resultNum;
}
int main() {
	int num;
	while (~scanf("%d", &num)) {
		printf("%d\n", getAns(num));
	}
}