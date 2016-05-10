class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(matrix.size() == 0) return;
        int row = matrix.size(), col = matrix[0].size();
        int rowzero = 1, colzero = 1;
        for(int i = 0; i < row; ++i)
        	if(matrix[i][0] == 0) colzero = 0;
    	for(int j = 0; j < col; ++j)
    	    if(matrix[0][j] == 0) rowzero = 0;
        for(int i = 1; i < row; ++i)
        	for(int j = 1; j < col; ++j)
        		if(matrix[i][j] == 0) matrix[i][0] = matrix[0][j] = 0;
        for(int i = 1; i < row; ++i)
        	if(matrix[i][0] == 0)
        	{
        		for(int j = 1; j < col; ++j) matrix[i][j] = 0;
        	}
        for(int j = 1; j < col; ++j)
        	if(matrix[0][j] == 0)
        	{
        		for(int i = 1; i < row; ++i) matrix[i][j] = 0;
        	}
        if(rowzero == 0) for(int j = 0;j < col; ++j) matrix[0][j] = 0;
        if(colzero == 0) for(int i = 0;i < row; ++i) matrix[i][0] = 0;
        return ;
    }
};