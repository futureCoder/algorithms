class Solution {
public:
    bool Find(vector<vector<int> > array,int target) {
        int m = array.size(), n = array[0].size();
        int cnt = 0, i = 0, j = n;
    	while(i < m && j >= 0) {
    		if(array[i][j] == target) {
    			++cnt;
    			if(i + 1 < m) ++i;
    			else if (j - 1 >= 0) --j;
    			else break;
    		}
    		else if(array[i][j] > target)
    			--j;

    		else
    			++i;
    	}
    }
};