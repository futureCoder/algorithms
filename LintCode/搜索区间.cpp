class Solution {
    /** 
     *@param A : an integer sorted array
     *@param target :  an integer to be inserted
     *return : a list of length 2, [index1, index2]
     */
public:
    vector<int> searchRange(vector<int> &A, int target) {
        int idx1, idx2;
        idx1 = getLeftIdx(A, target);
        idx2 = getRightIdx(A, target);
        return vector<int>{idx1, idx2};
    }
    int getLeftIdx(const vector<int> &A, int target) {
    	int start = 0, end = A.size();
        while(start < end) {
        	int mid = start + (end - start) / 2;
        	if(A[mid] == target && ((mid - 1 >= 0 && A[mid - 1] != target) || mid == 0))
        		return mid;
        	if(A[mid] >= target)
        		end = mid;
        	if(A[mid] < target)
        		start = mid + 1;
        }
        return -1;
    }
    int getRightIdx(const vector<int> &A, int target) {
    	int start = 0, end = A.size();
        while(start < end) {
        	int mid = start + (end - start) / 2;
        	if(A[mid] == target && ((mid + 1 < A.size() && A[mid + 1] != target) || mid == A.size() - 1))
        		return mid;
        	if(A[mid] > target)
        		end = mid;
        	if(A[mid] <= target)
        		start = mid + 1;
        }
        return -1;
    }
};