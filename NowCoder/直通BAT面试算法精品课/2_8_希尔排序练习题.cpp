class ShellSort {
public:
    int* shellSort(int* A, int n) {
        for(int step = 5; step > 0; step -= 2) {
            __shellPartSort(A, step, n);
        }
        return A;
    }
private:
    void __shellPartSort(int* a, int step, int len) {
        for(int i = step; i < len; ++i) {
            __shellInsert(a, i, step);
        }
    }
    void __shellInsert(int* a, int i, int step) {
        int value = a[i], last = i - step, limit = i % step;
        while(last >= limit && a[last] > value) {
            a[i] = a[last];
            i = last;
            last -= step;
        }
        a[i] = value;
    }
};