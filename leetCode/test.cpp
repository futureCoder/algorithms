class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int row = matrix.size(), col = matrix[0].size();
        for(int i = 0; i < row; ++i)
        {
            for(int j = 0; i + j < row - 1; ++j)
            {
                swap(matrix[i][j], matrix[col - 1 - j][row - 1 - i]);
            }
        }
        for(int i = 0; i < row / 2; ++i)
            for(int j = 0; j < col; ++j)
                swap(matrix[row - 1 - i][j],matrix[i][j]);
        return;
    }
};