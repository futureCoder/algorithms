class Solution {
public:
    //AC - with or without duplicates;
    vector<vector<int>> permute(vector<int>& nums) 
    {
        sort(nums.begin(), nums.end());
        int size = nums.size(), i, j;
        vector<vector<int>> vv;
        while(true)
        {
            vv.push_back(nums);
            int i = size-2, j = size-1;
            while(i>0 && nums[i]>=nums[i+1]) i--;
            while(j>0 && nums[i]>=nums[j]) j--;
            if(j == 0) break;
            swap(nums[i], nums[j]);
            j = size-1, i++;
            while(i<j)  swap(nums[i++], nums[j--]);     
        }
        return vv;
    }
};