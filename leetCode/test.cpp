class Solution {
public:
    int trap(vector<int>& height) 
    {
        if(height.size() < 3) return 0;
        int head = 0,tail = 0,index_b= -1;
        int ret = 0;
        head = tail;
        while(tail < height.size())
        {
        	while(tail < height.size() - 1 && height[tail] <= height[tail + 1]) ++tail;
    		
        	int tmp = 0;
        	while(tail < height.size() && height[tail] <= height[head])
        	{
        		tmp += (height[head] - height[tail]);
        		++tail;
        	}
        }
        return ret;
    }
};