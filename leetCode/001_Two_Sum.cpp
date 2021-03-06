class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mymap;
        vector<int> ret;
        for(int i = 0;i < nums.size(); ++i)
        {
        	if(mymap.find(target - nums[i]) != mymap.end())
        	{
        		int a = min(i,mymap[target - nums[i]]),b = max(i,mymap[target - nums[i]]);
        		ret.push_back(a);
        		ret.push_back(b);
        		return ret;
        	}
        	mymap[nums[i]] = i;
        }
        return ret;
    }
};