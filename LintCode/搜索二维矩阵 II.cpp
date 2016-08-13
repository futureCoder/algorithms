class Solution {
public:
    /**
     * @param matrix: A list of lists of integers
     * @param target: An integer you want to search in matrix
     * @return: An integer indicate the total occurrence of target in the given matrix
     */
    int searchMatrix(vector<vector<int> > &matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int cnt = 0, i = 0, j = n;
    	while(i < m && j >= 0) {
    		if(matrix[i][j] == target) {
    			++cnt;
    			if(i + 1 < m) ++i;
    			else if (j - 1 >= 0) --j;
    			else break;
    		}
    		else if(matrix[i][j] > target)
    			--j;
    		else
    			++i;
    	}
    }
};
