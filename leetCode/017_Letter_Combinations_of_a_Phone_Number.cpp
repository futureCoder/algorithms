class Solution {
public:
	void letterCombinations(string digits, string tmp, int k, vector<string>& ret) {
		if(k == digits.size()) {
			ret.push_back(tmp);
			return ;
		}
		for(int i = 0; i < key[digits[k] - '0'].size(); ++i) {
			letterCombinations(digits, tmp + key[digits[k] - '0'][i], k + 1, ret);
		}
	}
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
        return vector<string>();
    	vector<string> ret;
        letterCombinations(digits, string(""), 0, ret);
        return ret;
    }
private:
	vector<string> key = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
};