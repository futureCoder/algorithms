class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        int ret = -1,remain = 0;
        for(int i = 0; i < len; ++i)
        {
        	remain += (gas[i] - cost[i]);
        	if(ret == -1 && remain >= 0) ret = i;
        	if(remain < 0) 
        	{
        	    ret = -1;
        	    remain = 0;
        	}
        }
        if(ret > 0)
        	for(int i = 0; i < ret; ++i)
        	{
        		remain += (gas[i] - cost[i]);
        		if(remain < 0) ret = -1;
        	}
        return ret;
    }
};