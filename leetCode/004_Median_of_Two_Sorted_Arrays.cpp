class Solution {
public:
    double find_k(vector<int>::const_iterator nums1,int m, vector<int>::const_iterator nums2,int n, int k)
    {
        if(m > n) return find_k(nums2,n,nums1,m,k);
        if(m==0) return nums2[k-1];
        if(k == 1) return min(nums1[0],nums2[0]);
        int index_a = min((k/2),m), index_b = k - index_a;
        if(nums1[index_a - 1] == nums2[index_b - 1]) return nums1[index_a - 1];
        if(nums1[index_a - 1] > nums2[index_b - 1]) return find_k(nums1,m,nums2 + index_b,n- index_b ,k - index_b);
        else return find_k(nums1 + index_a,m - index_a,nums2,n,k - index_a);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(),n = nums2.size();
        if(m==0 && n==0) return 0;
        int k = (m + n) / 2 + 1;
        if((m+n) & 0x1) return find_k(nums1.begin(),nums1.size(),nums2.begin(),nums2.size(),k);
        else return (find_k(nums1.begin(),nums1.size(),nums2.begin(),nums2.size(),k) + find_k(nums1.begin(),nums1.size(),nums2.begin(),nums2.size(),k-1)) / 2.0;
    }
};