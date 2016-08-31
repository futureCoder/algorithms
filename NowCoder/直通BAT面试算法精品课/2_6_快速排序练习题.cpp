class QuickSort {
public:
	int* quickSort(int* A, int n) {
		if (NULL == A || n < 2)
			return A;
		int value = __median(A[0], A[n >> 1], A[n - 1]);
		int *pivot = partition(A, A + n, value);
		quickSort(A, pivot - A);
		quickSort(pivot, n - (pivot - A));
		return A;
	}
private:
	int* partition(int *first, int *last, int value) {
		while (first < last) {
			while (*first < value)
				++first;
			--last;
			while (*last > value)
				--last;
			if (!(first < last))
				return first;
			swap(*first, *last);
			++first;
		}
		return first;
	}
	int __median(int a, int b, int c) {
		if (a < b)
			if (b < c) //a < b < c
				return b;
			else if (a < c) // a < c <= b
				return c;
			else // c <= a < b
				return a;
		else if (a < c) // b <= a < c
			return a;
		else if (b < c) // b < c <= a
			return a;
		else    // c <= b <= a
			return  b;
	}
};