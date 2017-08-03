class Printer {
public:
    vector<int> printMatrix(vector<vector<int> > mat, int n, int m) {
    	bool leftToRight = true;
    	int step = 1;
    	vector<int> ret;

    	for(int i = 0; i < n; ++i) {
    		for(int j = leftToRight ? 0 : m - 1; 0 <= j && j < m ; j += step) {
    			ret.push_back(mat[i][j]);
    		}
    		leftToRight = !leftToRight;
    		step *= -1;
    	}

    return ret;
    }
};