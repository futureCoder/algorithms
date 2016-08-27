class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: An integer denote to find k non-overlapping subarrays
     * @return: An integer denote the sum of max k non-overlapping subarrays
     */
    int maxSubArray(vector<int> nums, int k) {
        int len = nums.size();
        if(len == 0 || len < k)
            return 0;
        int ret = nums[0];
        vector<vector<int>> dp(len + 1, vector<int>(k + 1, INT_MIN));
        for(int i = 0; i < len + 1; ++i)
            dp[i][0] = 0;
        for(int i = 0; i < k + 1; ++i)
            dp[0][i] = 0;
        for(int i = 1; i < len + 1; ++i) {
            for(int n = 1; n < min(i, k) + 1; ++n) {
                int fij = 0;
                for(int l = i - 1; l >= n - 1; --l) {
                    fij = max(fij + nums[l], nums[l]);
                    dp[i][n] = max(dp[i][n], dp[l][n - 1] + fij);
                }
            }
        }
        return dp[len][k];
    }
};
