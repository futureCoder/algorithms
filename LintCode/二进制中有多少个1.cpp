class Solution {
public:
    /**
     * @param num: an integer
     * @return: an integer, the number of ones in num
     */
    int countOnes(int num) {
        int cnt = 0;
        while(0 != num) {
        	++cnt;
        	num &= (num - 1);
        }
        return cnt;
    }
};