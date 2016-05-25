class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        map<int,bool> mymap;
        for(auto i : nums1)
        	mymap[i] = true;
        vector<int> ret;
        for(auto i : nums2)
        	if(mymap[i])
        	{
        		ret.push_back(i);
        		mymap[i] = false;
        	}
        return ret;
    }
};