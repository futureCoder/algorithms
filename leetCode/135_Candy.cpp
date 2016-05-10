class Solution {
public:
    int candy(vector<int>& ratings) 
    {
        int len = ratings.size();
        vector<int> nums(len,0);
        for(int i = 1; i < len; ++i)
            if(ratings[i - 1] < ratings[i]) nums[i] = nums[i - 1] + 1;
        for(int i = len - 2; i >= 0; --i)
            if (ratings[i] > ratings[i + 1]) nums[i] = max(nums[i], nums[i + 1] + 1);
        return accumulate(nums.begin(), nums.end(), len);
    }
};