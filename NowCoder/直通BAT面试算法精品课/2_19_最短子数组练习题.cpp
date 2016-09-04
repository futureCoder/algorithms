class Subsequence {
public:
    int shortestSubsequence(vector<int> A, int n) {
        int left = -1, leftMax = A[0], right = n - 1, rightMin = A[n - 1];
        for(int i = 1; i < n; ++i) {
            if(A[i] < leftMax)
                left = i;
            if(A[i] > leftMax)
                leftMax = A[i];
        }
        for(int i = right - 1; i >= 0; --i) {
            if(A[i] > rightMin)
                right = i;
            if(A[i] < rightMin)
                rightMin = A[i];
        }
        if(left == -1)
            return 0;
        else
            return left - right + 1;
    }
};