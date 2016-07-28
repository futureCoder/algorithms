class ShortSubsequence {
public:
    int findShortest(vector<int> A, int n) {
        // write code here
        int maxIdx = 0, minIdx = A.size() - 1, start = 0, end = 0;
        for(int i = 0; i < A.size(); ++i) {
        	if(A[i] > A[maxIdx]) {
        		maxIdx = i;
        	}
        	else if(A[i] < A[maxIdx]) {
        		end = i;
        	}
        }
        for(int i = size() - 1; i >= 0; --i) {
        	if(A[i] < A[minIdx]) {
        		minIdx = i;
        	}
        	else if(A[i] > A[minIdx]) {
        		start = i;
        	}
        }
        if(start >= end) 
        	return 0;
        return end - start + 1;
    }
};