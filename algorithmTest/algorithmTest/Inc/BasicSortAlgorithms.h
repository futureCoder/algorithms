#ifndef __BASIC_SORT_ALGORITHMS__H_
#define __BASIC_SORT_ALGORITHMS__H_
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

/********√∞≈›≈≈–Ú********/
class BubbleSort {
public:
	int* bubbleSort(int* A, int n);
};

/********—°‘Ò≈≈–Ú********/
class SelectionSort {
public:
	int* selectionSort(int* A, int n);
};
/********≤Â»Î≈≈–Ú********/
class InsertionSort {
public:
	int* insertionSort(int* A, int n);
	void __copy_backward(int *first, int *last, int value);
	void __unguard_linear_insert(int *last, int value);
};

/********πÈ≤¢≈≈–Ú********/
class MergeSort {
public:
	int* mergeSort(int* A, int n);
	int* merge(int *A, int*B, int lenA, int lenB, int len);
};

/********øÏÀŸ≈≈–Ú********/
class QuickSort {
public:
	int* quickSort(int* A, int n);
private:
	int* partition(int *first, int *last, int value);
	int __median(int a, int b, int c);
};

/********∂—≈≈–Ú********/
class HeapSort {
public:
	int* heapSort(int* A, int n);
private:
	void heapAdjust(int* a, int i, int len);
};

/********œ£∂˚≈≈–Ú********/
class ShellSort {
public:
	int* shellSort(int* A, int n);
private:
	void __shellPartSort(int* a, int step, int len);
	void __shellInsert(int* a, int i, int step);
};

/********º∆ ˝≈≈–Ú********/
class CountingSort {
public:
	int* countingSort(int* A, int n);
};

/********ª˘ ˝≈≈–Ú********/
class RadixSort {
public:
	int* radixSort(int* A, int n);
};

#endif