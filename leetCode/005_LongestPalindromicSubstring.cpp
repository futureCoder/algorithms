/**
 * Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
 * Example:
 * Input: "babad"
 * Output: "bab"
 * Note: "aba" is also a valid answer.
 * Example:
 * Input: "cbbd"
 * Output: "bb"
 */

class Solution {
public:
	string longestPalindrome(string s) {
		if (s.size() < 2)
			return s;
		auto GetAddBounadriesStr = [](const string& str) -> std::string {
			std::string ret;
			for (const auto& i : str)
			{
				ret.push_back('#');
				ret.push_back(i);
			}
			ret.push_back('#');
				return ret;
		};
		auto GetRemoveBounadriesStr = [](const string& str) -> std::string {
			std::string ret;
			for (int i = 0; i < str.size(); ++i) {
				++i;
				ret.push_back(str[i]);
			}
			return ret;
		};
		std::string str = std::move(GetAddBounadriesStr(s));
		std::vector<int> p(str.size(), 1);
		int id = 0, max = 0;
		for (int i = 0; i < str.size(); ++i)
		{
			if (i < max)
			{
				int j = 2 * id - i;
					if (p[j] + i < max)
					{
						p[i] = p[j];
						continue;
					}
			}
			int k = i + 1;
			while (k < str.size() && (2 * i - k) >= 0 && str[k] == str[2 * i - k])
			{
				++p[i];
				++k;
			}
			if (p[i] > p[id])
			{
				id = i;
				max = i + p[i];
			}
		}
		return GetRemoveBounadriesStr(str.substr(id - p[id] + 1, 2 * p[id] - 1));
	}
};