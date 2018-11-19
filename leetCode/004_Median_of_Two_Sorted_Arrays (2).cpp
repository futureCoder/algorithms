class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.empty() && nums2.empty())
        	return 0;
        if(nums1.size() > nums2.size())
        	return findMedianSortedArrays(nums2, nums1);
        int midIdx = (nums1.size() + nums2.size()) / 2;
    }
};