class InsertionSort {
public:
    int* insertionSort(int* A, int n) {
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
    void __copy_backward(int *first, int *last, int value) {
        int *next = last;
        --next;
        while(last != first) {
            *last = *next;
            last = next;
            --next;
        }
        *first = value;
    }
    void __unguard_linear_insert(int *last, int value) {
        int *next = last;
        --next;
        while(value < *next) {
            *last = *next;
            last = next;
            --next;
        }
        *last = value;
    }
};