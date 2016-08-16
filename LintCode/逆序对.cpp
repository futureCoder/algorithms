class Solution {
public:
    /**
     * @param A an array
     * @return total of reverse pairs
     */
    long long reversePairs(vector<int>& A) {
        long long cnt = 0;
        mergeSort(A, 0, A.size(), cnt);
        return cnt;
    }
    void mergeSort(vector<int>& A, int start, int end, long long &cnt) {
    	if(end - start <= 1)
    		return ;
    	int mid = start + (end - start) / 2;
    	mergeSort(A, start, mid, cnt);
    	mergeSort(A, mid, end, cnt);
    	vector<int> tmp1(A.begin() + start, A.begin() + mid);
    	vector<int> tmp2(A.begin() + mid, A.begin() + end);
    	int idx1 = tmp1.size() - 1, idx2 = tmp2.size() - 1, idx3 = end - 1;
    	while(idx1 >= 0 && idx2 >= 0) {
    		if(tmp1[idx1] > tmp2[idx2]) {
    			A[idx3--] = tmp1[idx1--];
    			cnt += (idx2 + 1);
    		}
    		if(tmp1[idx1] <= tmp2[idx2]) {
    			A[idx3--] = tmp2[idx2--];
    		}
    	}
    	while(idx1 >= 0)
    		A[idx3--] = tmp1[idx1--];
    	while(idx2 >= 0)
    		A[idx3--] = tmp2[idx2--];
    }
};