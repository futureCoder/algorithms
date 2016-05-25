class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()) return false;
        int row = matrix.size(), col = matrix.front().size();
        for(int i = 0,j = col - 1; i < row && j >= 0;)
        {
        	if(target == matrix[i][j]) return true;
        	else if(target > matrix[i][j]) ++i;
        	else --j;
        }
        return false;
    }
};