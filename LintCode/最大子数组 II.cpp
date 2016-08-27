class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: An integer denotes the sum of max two non-overlapping subarrays
     */
    int maxTwoSubArrays(vector<int> nums) {
      int len = nums.size();
      if(len < 2)
        return 0;
      int ret = INT_MIN, sum = 0, store = INT_MIN;
      vector<int> leftMax(len - 1, INT_MIN), rightMax(len - 1, INT_MIN);
      for(int i = 0; i < len - 1; ++i) {
        sum += nums[i];
        store = max(store, sum);
        leftMax[i] = store;
        if(sum < 0)
          sum = 0;
      }
      store = INT_MIN;
      sum = 0;
      for (int i = len - 2; i >= 0; --i) {
        sum += nums[i + 1];
        store = max(store, sum);
        rightMax[i] = store;
        if(sum < 0)
          sum = 0;
      }
      for(int i = 0; i < len - 1; ++i) {
        ret = max(ret, leftMax[i] + rightMax[i]);
      }
      return ret;
    }
};
