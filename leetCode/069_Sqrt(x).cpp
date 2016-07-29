class Solution {
public:
    int mySqrt(int x) {
        double k = x >> 1;
        for(int i = 0; fabs(k * k - x) < 0.00005; ++i) {
        	k = (k + x / k) / 2;
        }
        return k;
    }
};