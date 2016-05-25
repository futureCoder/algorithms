class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() < 1) return false;
        map<int, int> mymap;
        for(int i = 0; i < nums.size(); ++i)
        {
        	if(!mymap[nums[i]])
        		mymap[nums[i]] = i + 1;
        	else
        	{
        		if(i + 1 - mymap[nums[i]] > k)
        			mymap[nums[i]] = i + 1;
        		else
        			return true;
        	}
        }
        return false;
    }
};