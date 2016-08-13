class Solution {
public:
    /**
     * @param n an integer
     * @return a square matrix
     */
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ret(n, vector<int>(n));
        int k = 1;
        int x1 = 0, y1 = 0, x2 = n - 1, y2 = n - 1;
        while(x1 <= x2 && y1 <= y2)
        	generateMatrix(ret, x1++, y1++, x2--, y2--, k);
        return ret;
    }
    void generateMatrix(vector<vector<int>>& ret, int x1, int y1, int x2, int y2, int &k) {
    	int i = x1, j = y1;
    	while(j <= y2) 
    		ret[i][j++] = k++;
    	--j;
    	while(++i <= x2)
    		ret[i][j] = k++;
    	--i;
    	while(--j >= y1)
    		ret[i][j] = k++;
    	++j;
    	while(--i > x1)
    		ret[i][j] = k++;
    }
};