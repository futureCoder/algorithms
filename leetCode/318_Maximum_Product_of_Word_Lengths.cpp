class Solution {
public:
	int calcProduct(const map<char,bool>& mymap, const string& str2) {
		for(auto i : str2) {
			if(mymap.end() != mymap.find(i))
				return 0;
		}
		return str2.size();
	}
    int maxProduct(vector<string>& words) {
        int len = words.size();
        int ret = 0;
        for(int i = 0; i < len; ++i) {
        	std::map<char, bool> mymap;
        	int curLen = words[i].size();
        	for(auto c : words[i])
        		mymap[c] = true;
        	for(int j = i + 1; j < len; ++j)
        		ret = max(ret, curLen * calcProduct(mymap, words[j]));
        }
        return ret;
    }
};