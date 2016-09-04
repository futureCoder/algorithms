class ScaleSort {
public:
	vector<int> sortElement(vector<int> A, int n, int k) {
		if (n < 2)
			return A;
		vector<int> myHeap(A.begin(), A.begin() + k);
		makeHeap(myHeap);
		for (int i = k; i < A.size(); ++i) {
			A[i - k] = myHeap[0];
			myHeap[0] = A[i];
			heapAdjust(myHeap, 0, k);
		}
		for (int i = A.size() - k; i < A.size(); ++i) {
			A[i] = myHeap[0];
			swap(myHeap[0], myHeap[k - 1]);
			heapAdjust(myHeap, 0, --k);
		}
		return A;
	}
private:
	void makeHeap(vector<int> &a) {
		for (int i = a.size() / 2 - 1; i >= 0; --i)
			heapAdjust(a, i, a.size());
	}
	void heapAdjust(vector<int> &a, int i, int len) {
		int nChild;
		for (int nTmp = a[i]; 2 * i + 1 < len; i = nChild) {
			nChild = 2 * i + 1;
			if (nChild + 1 < len && a[nChild + 1] < a[nChild])
				++nChild;
			if (a[i] > a[nChild]) {
				a[i] = a[nChild];
				a[nChild] = nTmp;
			}
			else
				return;
		}
	}
};