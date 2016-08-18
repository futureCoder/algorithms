class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
    vector<int> medianII(vector<int> &nums) {
        
    }
    void heapAdjust(vector<int> &myvec, int i, int len) {
    	int nChild, nTmp;
    	while(nTmp = myvec[i]; 2 * i + 1 < len; i = nChild) {
    		nChild = 2 * i + 1;
    		if(nChild + 1 < len && myvec[nChild + 1] > myvec[nChild])
    			++nChild;
    		if(myvec[])
    	}
    }
};
