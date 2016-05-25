class Solution {
public:
    vector<int> countBits(int num) {
    	vector<int> ret(num+1,0);
        for(int i = 1; i <= num; ++i)
        {
        	if(!(i & (i - 1))) ret[i] = 1;
        	else
        	{
        		int tmp = i & (i - 1);
        		ret[i] = ret[tmp] + 1;
        	}
        }
        return ret;
    }
};