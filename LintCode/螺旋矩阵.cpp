class Solution {
public:
    /**
     * @param matrix a matrix of m x n elements
     * @return an integer array
     */
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    	vector<int> ret;
    	if(matrix.empty())
    		return ret;
        int m = matrix.size(), n = matrix[0].size();
        int x1 = 0, y1 = 0, x2 = m - 1, y2 = n - 1;
        while(x1 <= x2 && y1 <= y2) 
        	spiralOrder(matrix, x1++, y1++, x2--, y2--, ret);
        return ret;
    }
    void spiralOrder(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2, vector<int>& ret) {
    	int i = x1, j = y1;
    	while(j <= y2)
    		ret.push_back(matrix[i][j++]);
    	--j;
    	while(++i <= x2)
    		ret.push_back(matrix[i][j]);
    	--i;
    	if(x1 == x2 || y1 == y2)
    		return ;
    	while(--j >= y1)
    		ret.push_back(matrix[i][j]);
    	++j;
    	while(--i > x1)
    		ret.push_back(matrix[i][j]);
    }
};