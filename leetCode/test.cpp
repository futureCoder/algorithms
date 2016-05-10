class Solution {
public:
    int trap(vector<int>& height) 
    {
        int len = height.size();
        vector<int> leftmax(len),rightmax(len);
        for(int i = 0; i < len; ++i)
        {
            if(i == 0) leftmax[0] = 0;
            
        }
    }
};