class Solution {
public:
	vector<vector<int> > subsets(vector<int> &S) {
		sort(S.begin(), S.end());
		vector<vector<int> > result;
		const size_t n = S.size();
		vector<int> v;
		for (size_t i = 0; i < 1 << n; i++) {
			for (size_t j = 0; j < n; j++) {
				if (i & 1 << j) v.push_back(S[j]);
			}
			result.push_back(v);
			v.clear();
		}
		return result;
	}
};