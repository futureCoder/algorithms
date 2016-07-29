class MaxGap {
public:
    int findMaxGap(vector<int> A, int n) {
        // write code here
        int maxNum = A[0];
        for(auto i : A) 
        	maxNum = max(i, maxNum);
        return maxNum - min(A[0], A[n - 1]);
    }
};