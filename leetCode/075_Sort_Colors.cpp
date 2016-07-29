class Solution {
public:
	void heapAdjust(vector<int>& nums, int i, int len) {
		int nChild;
		for(; 2 * i + 1< len; i = nChild) {
			nChild = 2 * i + 1;
			if(nChild + 1 < len && nums[nChild + 1] > nums[nChild]) ++nChild;
			if(nums[i] < nums[nChild]) 
				swap(nums[i], nums[nChild]);
		}
	}
	void heapSort(vector<int>& nums) {
		int len = nums.size();
		for(int i = len - 1; i >= 0; --i)
			heapAdjust(nums, i, len);
		for(int i = len - 1; i > 0; --i) {
			swap(nums[0], nums[i]);
			heapAdjust(nums, 0, i);
		}
	}
    void sortColors(vector<int>& nums) {
        heapSort(nums);
    }
};