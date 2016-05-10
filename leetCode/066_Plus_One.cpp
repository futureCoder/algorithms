class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        if(digits.size() == 0) 
        {
            digits.push_back(1);
            return digits;
        }
        reverse(digits.begin(), digits.end());
        int cf = 0;
        digits[0] += 1;
        for(int i = 0; i < digits.size(); ++i)
        {
        	digits[i] += cf;
        	if(digits[i] < 10) break;
        	cf = digits[i] / 10;
        	digits[i] %= 10;
        }
        if(cf) digits.push_back(cf);
        reverse(digits.begin(), digits.end());
        return digits;
    }
};