class Finder {
public:
    bool findX(vector<vector<int> > mat, int n, int m, int x) {
        if(mat.empty())
            return false;
        int i = 0, j = mat[0].size() - 1;
        while(i < mat.size() && j >= 0) {
            if(x == mat[i][j])
                return true;
            if(x > mat[i][j])
                ++i;
            else 
                --j;
        }
        return false;
    }
};