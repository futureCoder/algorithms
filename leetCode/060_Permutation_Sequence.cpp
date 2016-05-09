class Solution {
public:
	char find_t(vector<int> &hash, int t)
	{
		int i = 0;
		while(hash[i]!=t && i < hash.size()) ++i;
		char ret = (i + 1) + '0';
		hash[i] = -1;
		while(++i<hash.size()) --hash[i];
		return ret;
	}
    string getPermutation(int n, int k) {
        vector<int> hash(n);
        int total = 1;
        k--;
        for(int i = 0;i < n; ++i)
        {
        	hash[i] = i;
        	total *= (i + 1);
        }
        string ret(n,0);
        for(int i = n; i > 0; --i)
        {
        	total /= i;
        	int tmp = k / total;
        	ret[n-i] = find_t(hash,tmp);
        	k %= total;
        }
        return ret;
    }
};