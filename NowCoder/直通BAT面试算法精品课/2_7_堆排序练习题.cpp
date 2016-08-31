class HeapSort {
public:
	int* heapSort(int* A, int n) {
        if(NULL == A || n < 2)
            return A;
		for (int i = (n >> 1) - 1; i >= 0; --i)
			heapAdjust(A, i, n);
		for (int i = n - 1; i > 0; --i) {
			swap(A[i], A[0]);
			heapAdjust(A, 0, i);
		}
		return A;
	}
private:
	void heapAdjust(int* a, int i, int len) {
		int nChild;
		for (int nTmp = a[i]; 2 * i + 1 < len; i = nChild) {
			nChild = 2 * i + 1;
			if (nChild + 1 < len && a[nChild + 1] > a[nChild])
				++nChild;
			if (a[nChild] > a[i]) {
				a[i] = a[nChild];
				a[nChild] = nTmp;
			}
			else
				return;
		}
	}
};