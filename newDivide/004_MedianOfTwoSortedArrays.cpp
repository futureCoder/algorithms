/**
 * There are two sorted arrays nums1 and nums2 of size m and n respectively.
 * Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
 * Example 1:
 * nums1 = [1, 3]
 * nums2 = [2]
 * The median is 2.0
 * 
 * Example 2:
 * nums1 = [1, 2]
 * nums2 = [3, 4]
 * The median is (2 + 3)/2 = 2.5
 */

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int mid = (m + n) >> 1;
        if(m < mid)
        {
            return nums2[mid - m];
        }
        if(n < mid)
        {
            return nums1[mid - n];
        }

        int find_Kth_InSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n, int k)
        {
            if(m < k)
            {
                return nums2[n - k];
            }
        }

        int lowwer_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n)
        {

        }
        int upper_findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2, int m, int n)
        {
            
        }
    }
};