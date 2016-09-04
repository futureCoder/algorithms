class Merge {
public:
    int* mergeAB(int* A, int* B, int n, int m) {
        int pos = n + m - 1;
        --n, --m;
        while(n >= 0 && m >= 0) {
            if(A[n] > B[m]) 
                A[pos--] = A[n--];
            else
                A[pos--] = B[m--];
        }
        while(n >= 0)
            A[pos--] = A[n--];
        while(m >= 0)
            A[pos--] = B[m--];
        return A;
    }
};