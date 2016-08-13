class Solution {
public:
    /*
     * param k : description of k
     * param nums : description of array and index 0 ~ n-1
     * return: description of return
     */
    int kthLargestElement(int k, vector<int> nums) {
        if(k < 1 || k > nums.size())
        	return 0;
        int len = nums.size();
        for(int i = nums.size() / 2 - 1; i >= 0; --i)
        	heapAdjust(nums, i, nums.size());
        for(int i = nums.size() - 1; i >= len - k; --i) {
        	swap(nums[0], nums[i]);
        	heapAdjust(nums, 0, i);
        }
        return nums[len - k];
    }
    void heapAdjust(vector<int> &nums, int i, int len) {
    	int nChild, nTmp;
    	for(nTmp = nums[i]; 2 * i + 1 < len; i = nChild) {
    		nChild = 2 * i + 1;
    		if(nChild + 1 < len && nums[nChild + 1] > nums[nChild]) 
    			++nChild;
    		if(nums[i] < nums[nChild]) {
    			nums[i] = nums[nChild];
    			nums[nChild] = nTmp;
    		}
    		else
    			break;
    	}
    }
};