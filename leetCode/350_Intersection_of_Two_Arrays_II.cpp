class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        map<int,int> mymap;
        for(auto i : nums1)
        	++mymap[i];
        vector<int> ret;
        for(auto i : nums2)
        {
        	if(mymap[i])
        	{
        		ret.push_back(i);
        		--mymap[i];
        	}
        }
        return ret;
    }
};