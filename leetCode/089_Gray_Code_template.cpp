class Solution {
public:
	vector<int> grayCode(int n) 
	{
		vector<int> result;
		result.reserve(1<<n);
		result.push_back(0);
		for (int i = 0; i < n; i++) 
		{
			const int highest_bit = 1 << i;
			for (int j = result.size() - 1; j >= 0; j--)	//反向遍历,才能对称
			result.push_back(highest_bit | result[j]);
		}
	return result;
	}
};