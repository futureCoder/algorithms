class Solution {
public:
	void makeNext(const string &p,vector<int> next)
	{
		int i,k = 0,len = p.size();
		next[0] = 0;
		for(i = 0;i < len; ++i)
		{
			while(k > 0 && p[i] != p[k]) k = next[k - 1];
			if(p[i] == p[k]) ++k;
			next[i] = k;
		}
	}
	int kmp(const string &t,const string *p)
	{
		
	}
    bool isMatch(string s, string p) {
        
    } 
};