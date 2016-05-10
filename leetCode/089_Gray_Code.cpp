class Solution {
public:
    vector<int> grayCode(int n) {
        std::vector<int> ret;
        int len = 1 << n;
        for(int i = 0; i < len; ++i)
        	ret.push_back(i ^ (i >> 1);
        return ret;
    }
};