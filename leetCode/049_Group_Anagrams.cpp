class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> ret;
		int n = strs.size();
		while(n != 0) {
			map<int, bool> mymap;
			vector<string> tmp;
			int curLen = strs[n - 1].size();
			for(int string_index = 0; string_index < curLen; ++string_index) {
				mymap.insert(make_pair(strs[n - 1][string_index], true));
			}
			tmp.push_back(strs[n - 1]);
			--n;
			for(int strs_index = 0; strs_index < n; ) {
				if(strs[strs_index].size() == curLen) {
					bool isMatch = true;
					for(int string_index = 0; string_index < strs[strs_index].size(); ++string_index) {
						isMatch &= (mymap.find(strs[strs_index][string_index]) != mymap.end());
					}
					if(isMatch) {
						tmp.push_back(strs[strs_index]);
						swap(strs[strs_index], strs[n - 1]);
						--n;
					}
					else {
						++strs_index;
					}
				}
				else {
					++strs_index;
				}
			}
			ret.push_back(tmp);
		}
		return ret;
	}
};