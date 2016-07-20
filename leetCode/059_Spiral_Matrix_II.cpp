class Solution {
public:
	void generateMatrix(const int &x1, const int &y1, const int &x2, const int &y2, vector<vector<int>> &vec) {
	    if(x1 == x2 && y1 == y2) {
	        vec[x1][y1] = ++count;
	        return;
	    }
		int i = x1, j = y1;
		while(j <= y2)
			vec[i][j++] = ++count;
		++i,--j;
		while(i <= x2)
			vec[i++][j] = ++count;
		--i,--j;
		while(j >= y1)
			vec[i][j--] = ++count;
		--i,++j;
		while(i > x1)
			vec[i--][j] = ++count;
	}
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> vec(n, vector<int>(n));
        count = 0;
        if(0 == n)
        	return vec;
        int x1 = 0, y1 = 0, x2 = n - 1, y2 = n - 1;
        while(x1 <= x2 && y1 <= y2)
        	generateMatrix(x1++, y1++, x2--, y2--, vec);
        return vec;
    }
private:
	int count;
};