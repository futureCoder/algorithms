class Solution {
public:
    /**
     * @param nums: A list of integers
     * @param k: As described
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums, int k) {
        map<int, int> mymap;
        for(auto i : nums) {
            if(mymap.end() != mymap.find(i)) {
                ++mymap[i];
                continue;
            }
            if(mymap.size() < k - 1) {
                mymap.insert({i, 1});
            }
            else {
                auto pos = mymap.find(i);
                if(pos != mymap.end()) {
                    ++pos->second;
                }
                else {
                    for(auto itr = mymap.begin(); itr != mymap.end(); ) {
                        --itr->second;
                        if(itr->second == 0) {
                            itr = mymap.erase(itr);
                        }
                        else {
                            ++itr;
                        }
                    }
                }
            }
        }
        int ret, maxCnt = 0, tmp;
        for(auto itr = mymap.begin(); itr != mymap.end(); ++itr) {
            if((tmp = count(nums.begin(), nums.end(), itr->first)) > maxCnt) {
                maxCnt = tmp;
                ret = itr->first;
            }
        }
        return ret;
    }
};
