class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size() < 2) return 1;
        std::unordered_map<int, pair<bool,int>> mymap;	//false代表序列首字母
        int ret = 1;
        for(auto &i : nums)
        {
        	if(mymap[i].second == 0 && mymap[i].first == false)
        	{   
        	    mymap[i].second = 1;
	            if(mymap[i-1].second == 0 && mymap[i-1].first == false)	//若前一位数字是序列开始且长度为0(即不存在前一位)
                ;
	            else if(mymap[i-1].first == false)	//前一位是当前序列开始位
	            {
	            	mymap[i].first = true;
	            	mymap[i].second = i-1;
	            	mymap[i-1].second++;
	            	if(ret < mymap[i-1].second) ret = mymap[i-1].second;
	            }
	            else 
	            {
	                int index = mymap[i-1].second;
	            	while(mymap[index].first!=false) index = mymap[index].second;
	            	mymap[i].first = true;
	            	mymap[i].second = index;
	            	mymap[index].second++;
	            	if(ret < mymap[index].second) ret = mymap[index].second;
	            }   //i-1 handle over
	            if(mymap[i+1].second == 0 && mymap[i+1].first == false) continue;
	            else if(mymap[i+1].first == false)
	            {
	            	mymap[i+1].first = true;
	            	if(mymap[i].first==false)
	            	{
	            		mymap[i].second += mymap[i+1].second;
	            		mymap[i+1].second = i;
	            		if(ret < mymap[i].second) ret = mymap[i].second;
	            	}
	            	else
	            	{
	            		int index = mymap[i].second;
	            		while(mymap[index].first!=false) index = mymap[index].second;
	            		mymap[index].second += mymap[i+1].second;
	            		mymap[i+1].second = index;
	            		if(ret < mymap[index].second) ret = mymap[index].second;
	            	}
	            }
        	}
        }
        return ret;
    }
};