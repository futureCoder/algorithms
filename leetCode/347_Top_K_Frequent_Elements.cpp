class Solution {
public:
	static int cmp(const pair<int, int>& a, const pair<int, int>& b) {
		return a.second > b.second;
	}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> mymap;
        for(auto i : nums)
        	++mymap[i];
        vector<pair<int, int>> myvec;
        vector<int> ret;
        for(auto i : mymap)
        	myvec.push_back(make_pair(i.first, i.second));
        sort(myvec.begin(), myvec.end(), cmp);
        for(int i = 0; i < k; ++i)
        	ret.push_back(myvec[i].first);
        return ret;
    }
};