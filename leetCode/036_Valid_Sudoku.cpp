class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i = 0;i < 9; ++i)
        {
        	int row[9] = {0},col[9] = {0};
        	for(int j = 0;j < 9; ++j)	
        	{
        		char r = board[i][j], c = board[j][i];
        		if(r != '.')
        		{
					if(row[r - '1' ] == 0) ++row[r - '1'];
        			else return false;
        		}
        		if(c != '.')
        		{
					if(col[c - '1' ] == 0) ++col[c - '1'];
        			else return false;
        		}
        	}
        }
        for(int i = 0;i < 9; i += 3)
        {
        	for(int j = 0;j < 9;j += 3)
        	{
        		int chunk[9] = {0};
        		for(int a = 0;a < 3; ++a)
        		{
        			for(int b = 0; b < 3; ++b)
        			{
        				if(board[i+a][j+b] == '.') continue;
        				if(chunk[board[i+a][j+b] - '1'] == 0) ++chunk[board[i+a][j+b] - '1'];
        					else return false;
        			}
        		}
        	}
        }
        return true;
    }
};