class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ret;
        if(nums.size()<3) return ret;
        sort(nums.begin(), nums.end());
        for(int i = 0;i < nums.size()-2;++i)
        {
            if(i>0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = nums.size() - 1;
            while(j<k)
            {
                if(nums[i] + nums[j] + nums[k] < 0) 
                {
                    ++j;
                    while(nums[j] == nums[j-1] && j < k) ++j;
                }
                else if(nums[i] + nums[j] + nums[k] > 0)
                {
                    --k;
                    while(nums[k] == nums[k+1] && j < k) --k;
                }
                else 
                {
                    ret.push_back({nums[i],nums[j],nums[k]});
                    ++j;
                    --k;
                    while(nums[j] == nums[j-1] && j < k) ++j;
                    while(nums[k] == nums[k+1] && j < k) --k;
                }
            }
        }
        return ret;
    }
};