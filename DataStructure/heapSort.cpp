#include <iostream>
#include <vector>
#include <algorithm>

void heapAdjustArray(std::vector<int> &vec, int i, int len) {
	for(int nChild = 2 * i + 1, tmp = vec[i]; nChild < len; i = nChild) {
		if(nChild + 1 < len && vec[nChild + 1] > vec[nChild]) ++nChild;
		if(vec[i] < vec[nChild]) 
			std::swap(vec[i], vec[nChild]);
		else 
			break;
	}
}

void heapSortArray(std::vector<int> &vec) {
	int len = vec.size();
	for(int i = (len - 1) / 2; i >=0; --i)
		heapAdjustArray(vec, i, len);
	for(int i = len - 1; i > 0; --i) {
		std::swap(vec[0], vec[i]);
		heapAdjustArray(vec, 0, i);
	}
}

int main() {
	freopen("in.txt", "r", stdin);
	int k;
	while(std::cin>>k) {
		std::vector<int> vec(k);
		for(int i = 0; i < k; ++i)
			std::cin>>vec[i];
		for(int i = 0; i < k; ++i)
			std::cout << vec[i] << ' ';
		std::cout<<std::endl;
		heapSortArray(vec);
		std::cout<<"after heapSort"<<std::endl;
		for(int i = 0; i < k; ++i)
			std::cout << vec[i] << ' ';
		std::cout<<std::endl;
	}
}
