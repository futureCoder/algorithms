class RadixSort {
public:
	int* radixSort(int* A, int n) {
		vector<queue<int>> bucket(10);
		int weight = 1, idx;
		while (1) {
			for (idx = 0; idx < n; ++idx) {
				bucket[(A[idx] / weight) % 10].push(A[idx]);
			}
			idx = 0;
			for (auto &i : bucket) {
				int cnt = 0;
				while (!i.empty()) {
					A[idx++] = i.front();
					i.pop();
					++cnt;
				}
				if (cnt == n)
					return A;
			}
			weight *= 10;
		}
		return A;
	}
};