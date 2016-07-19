class Solution {
public:
	void printEdge(vector<vector<int>>& matrix, int x1, int y1, int x2, int y2) {
		if(x1 == x2 && y1 == y2) {
			vec.push_back(matrix[x1][y1]);
			return;
		}
		int i = x1, j = y1;
		while(j <= y2)
			vec.push_back(matrix[i][j++]);
		++i;
		--j;
		while(i <= x2)
			vec.push_back(matrix[i++][j]);
		--i;
		--j;
		if(x1 == x2 || y1 == y2)
			return;
		while(j >= y1)
			vec.push_back(matrix[i][j--]);
		--i;
		++j;
		while(i > x1)
			vec.push_back(matrix[i--][j]);
	}
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vec.clear();
        if(matrix.empty()) return vec;
        int x1 = 0, y1 = 0, x2= matrix.size() - 1, y2 = matrix[0].size() - 1;
        while(x1 <= x2 && y1 <= y2)
        	printEdge(matrix, x1++, y1++, x2--, y2--);
        return vec;

    }
private:
	vector<int> vec;
};