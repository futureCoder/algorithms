class SelectionSort {
public:
    int* selectionSort(int* A, int n) {
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
};