#include <iostream.h>
#include <vector>
#include <random>
#include <stdlib.h>
#include <time.h>

int getRand(int start, int end) {
	srand((int)time(0));
	return rand() % (end - start + 1) + start;
}

void partition(vector<int> &array, int start, int end) {
	
}

void quickSortArray(vector<int> &array) {
	if(array.empty())
		return ;
	partition(array,0, array.size() - 1);
}

int main() {
	
}