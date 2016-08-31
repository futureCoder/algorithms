class MergeSort {
public:
	int* mergeSort(int* A, int n) {
		if (NULL == A || n < 2)
			return A;
		int mid = n >> 1;
		mergeSort(A, mid);
		mergeSort(A + mid, n - mid);
		int leftLen = mid, rightLen = n - mid;
		merge(A, A + mid, leftLen, rightLen, n);
		return A;
	}
	int* merge(int *A, int*B, int lenA, int lenB, int len) {
		int last = len - 1, lastA = lenA - 1, lastB = lenB - 1;
		int *tmpB = (int *)malloc(lenB * sizeof(int));
		memcpy(tmpB, B, lenB * sizeof(int));
		while (lastA >= 0 && lastB >= 0) {
			if (A[lastA] > tmpB[lastB])
				A[last--] = A[lastA--];
			else
				A[last--] = tmpB[lastB--];
		}
		while (lastA >= 0)
			A[last--] = A[lastA--];
		while (lastB >= 0)
			A[last--] = tmpB[lastB--];
		free(tmpB);
		return A;
	}
};