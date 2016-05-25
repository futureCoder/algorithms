class Solution {
public:
	bool isIsomorphic(string s, string t) {
		map<char, int> smap, tmap;
		for(int i = 0; i < s.size(); ++i)
		{
			if(!smap[s[i]] && !tmap[t[i]])
				smap[s[i]] = tmap[t[i]] = i + 1;
			else if(smap[s[i]] == tmap[t[i]])
			{
				smap[s[i]] = tmap[t[i]] = i + 1;
			}
			else 
				return false;
		}
		return true;
	}
};