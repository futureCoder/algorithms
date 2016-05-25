class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        if(row == 0) return false;
        for(int i = 0; i < row; ++i)
        {
        	if(matrix[i][0] <= target && target <= matrix[i][col - 1])
        	{
        		for(int j = 0; j < col; ++j)
        			if(target == matrix[i][j]) return true;
        	}
        	if(matrix[i][0] > target) return false;
        }
        return false;
    }
};