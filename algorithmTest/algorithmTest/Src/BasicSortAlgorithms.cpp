#include "BasicSortAlgorithms.h"
/********冒泡排序********/
int* BubbleSort::bubbleSort(int* A, int n) {
if(NULL == A || n < 2)
    return A;
for(int i = n - 1; i > 0; --i)
    for(int j = 0; j < i; ++j) {
        if(A[j] > A[j + 1])
            swap(A[j], A[j + 1]);
    }
return A;
}

/********选择排序********/

int* SelectionSort::selectionSort(int* A, int n) {
    if(NULL == A || n < 2)
        return A;
    for(int i = n - 1; i > 0; --i) {
        int pos = i;
        for(int j = 0; j <= i; ++j) {
            if(A[j] > A[pos])
                pos = j;
        }
        swap(A[i], A[pos]);
    }
    return A;
}
/********插入排序********/

int* InsertionSort::insertionSort(int* A, int n) {
    if(NULL == A || n < 2)
        return A;
    for(int i = 1; i < n; ++i) {
        int value = A[i];
        if(value < A[0])
            __copy_backward(A, A + i, value);
        else
            __unguard_linear_insert(A + i, value);
    }
    return A;
}
void InsertionSort::__copy_backward(int *first, int *last, int value) {
    int *next = last;
    --next;
    while(last != first) {
        *last = *next;
        last = next;
        --next;
    }
    *first = value;
}
void InsertionSort::__unguard_linear_insert(int *last, int value) {
    int *next = last;
    --next;
    while(value < *next) {
        *last = *next;
        last = next;
        --next;
    }
    *last = value;
}

/********归并排序********/
int* MergeSort::mergeSort(int* A, int n) {
	if (NULL == A || n < 2)
		return A;
	int mid = n >> 1;
	mergeSort(A, mid);
	mergeSort(A + mid, n - mid);
	int leftLen = mid, rightLen = n - mid;
	merge(A, A + mid, leftLen, rightLen, n);
	return A;
}
int* MergeSort::merge(int *A, int*B, int lenA, int lenB, int len) {
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

/********快速排序********/
int* QuickSort::quickSort(int* A, int n) {
	if (NULL == A || n < 2)
		return A;
	int value = __median(A[0], A[n >> 1], A[n - 1]);
	int *pivot = partition(A, A + n, value);
	quickSort(A, pivot - A);
	quickSort(pivot, n - (pivot - A));
	return A;
}
int* QuickSort::partition(int *first, int *last, int value) {
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
int QuickSort::__median(int a, int b, int c) {
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

/********堆排序********/
int* HeapSort::heapSort(int* A, int n) {
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
void HeapSort::heapAdjust(int* a, int i, int len) {
	int nChild;
	for (int nTmp = a[i]; 2 * i + 1 < len; i = nChild) {
		nChild = 2 * i + 1;
		if (nChild + 1 < len && a[nChild + 1] > a[nChild])
			++nChild;
		if (a[nChild] > a[i]) {
			a[i] = a[nChild];
			a[nChild] = nTmp;   //swap(a[i], a[nChild]);
		}
		else
			return;
	}
}

/********希尔排序********/
int* ShellSort::shellSort(int* A, int n) {
    for(int step = 5; step > 0; step -= 2) {
        __shellPartSort(A, step, n);
    }
    return A;
}
void ShellSort::__shellPartSort(int* a, int step, int len) {
    for(int i = step; i < len; ++i) {
        __shellInsert(a, i, step);
    }
}
void ShellSort::__shellInsert(int* a, int i, int step) {
    int value = a[i], last = i - step, limit = i % step;
    while(last >= limit && a[last] > value) {
        a[i] = a[last];
        i = last;
        last -= step;
    }
    a[i] = value;
}

/********计数排序********/
int* CountingSort::countingSort(int* A, int n) {
    if(NULL == A || n < 2)
        return A;
    int _min = A[0], _max = A[0];
    for(int i = 0; i < n; ++i) {
        _min = min(_min, A[i]);
        _max = max(_max, A[i]);
    }
    vector<int> bucket(_max - _min + 1, 0);
    for(int i = 0; i < n; ++i)
        ++bucket[A[i] - _min];
    int pos = 0;
    for(int i = 0; i < bucket.size(); ++i) {
        while(bucket[i]) {
            A[pos++] = i + _min;
            --bucket[i];
        }
    }
    return A;
}

/********基数排序********/
int* RadixSort::radixSort(int* A, int n) {
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