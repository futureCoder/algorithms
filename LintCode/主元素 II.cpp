class Solution {
public:
    /**
     * @param nums: A list of integers
     * @return: The majority number occurs more than 1/3.
     */
    int majorityNumber(vector<int> nums) {
        int can1, can2, cnt1 = 0, cnt2 = 0;
        for(auto i : nums) {
        	if(i == can1) 
        		++cnt1;
        	else if(i == can2)
        		++cnt2;
        	else if(0 == cnt1) {
        		can1 = i;
        		++cnt1;
        	}
        	else if(0 == cnt2) {
        		can2 = i;
        		++cnt2;
        	}
        	else {
        		--cnt1;
        		--cnt2;
        	}
        }
        cnt1 = 0;
        cnt2 = 0;
        for(auto i : nums) {
        	if(i == can1)
        		++cnt1;
        	else if(i == can2)
        		++cnt2;
        }
        if(cnt1 > cnt2)
        	return can1;
        else 
        	return can2;
    }
};
