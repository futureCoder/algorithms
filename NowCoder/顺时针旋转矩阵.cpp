class Rotate {
public:
	void spinMatrix(const vector<vector<int>> &mat, vector<vector<int>> &ret) {
		int n = mat.size() - 1;
		for(int i = 0, y = 0; i <= n; ++i, ++y) {
			for(int j = 0, x = n; j <= n; ++j, --x)
				ret[i][j] = mat[x][y];
		}
	}
    vector<vector<int> > rotateMatrix(vector<vector<int> > mat, int n) {
        vector<vector<int>> ret(mat);
        spinMatrix(mat, ret);
        return ret;
    }
};