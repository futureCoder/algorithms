class CountingSort {
public:
    int* countingSort(int* A, int n) {
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
};