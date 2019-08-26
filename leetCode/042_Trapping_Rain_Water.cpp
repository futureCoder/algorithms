class Solution {
public:
    int trap(vector<int>& height) 
    {
        int len = height.size();
        int leftmax = 0,rightmax = 0;
        int ret = 0;
        vector<int> right(len);
        for(int i = len-1; i > 0; --i)
        {
            right[i] = rightmax;
            rightmax = std::max(rightmax, height[i]);
        }
        for(int i = 0; i < len; ++i)
        {
            int max = min(leftmax,right[i]);
            leftmax = std::max(leftmax, height[i]);
            if(max <= height[i]) 
                continue;
            ret += (max - height[i]);
        }
        return ret;
    }
};