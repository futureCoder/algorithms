class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number
     */
    int majorityNumber(vector<int> nums) {
    	if(nums.empty())
    		return 0;
        pair<int, int> candidate;
        candidate.second = 0;
        for(const auto &i : nums) {
        	if(0 == candidate.second) {
        		candidate.first = i;
        		++candidate.second;
        	}
        	else {
        		if(i == candidate.first) 
        			++candidate.second;
        		else {
        			--candidate.second;
        		}
        	}
        }
        return candidate.first;
    }
};
