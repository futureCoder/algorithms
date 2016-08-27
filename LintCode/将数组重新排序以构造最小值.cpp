class Solution {
public:
    /**
     * @param nums n non-negative integer array
     * @return a string
     */
    string minNumber(vector<int>& nums) {
        std::sort(nums.begin(), nums.end(), cmp);
        string ret;
        int cnt = 0;
        for(auto i : nums) {
            string tmp = to_string(i);
            ret += tmp;
        }
        int idx = 0;
        while(idx < ret.size() && ret[idx] == '0') 
            ++idx;
        if(idx == ret.size())
            return ret.substr(0, 1);
        else
            return ret.substr(idx, ret.size() - idx);
    }
    static int cmp(const int &a, const int &b) {
        string sa = std::to_string(a), sb = std::to_string(b);
        string tmp = sa;
        sa += sb,sb += tmp;
        if(sa.compare(sb) < 0)
            return 1;
        else
            return 0;
    }
};