class Solution {
public:
    /**
     * @param matrix, a list of lists of integers
     * @param target, an integer
     * @return a boolean, indicate whether matrix contains target
     */
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
    	if(matrix.empty())
    		return false;
    	int m = matrix.size(), n = matrix[0].size();
        int start = 0, end = m * n;
        while(start < end) {
        	int mid = start + (end - start) / 2;
        	pair<int, int> s = getIdx(m, n, start), e = getIdx(m, n, end), mmid = getIdx(m, n, mid);
        	if(matrix[mmid.first][mmid.second] == target)
        		return true;
        	else if(matrix[mmid.first][mmid.second] > target)
        		end = mid;
        	else
        		start = mid + 1;
        }
        return false;
    }
    pair<int, int> getIdx(const int m, const int n, const int k) {
    	return {k / n, k % n};
    }
};
