class Solution {
public:
    /**
     * @param num: a rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int start = 0, end = num.size();
        while(start < end) {
        	int mid = start + (end - start) / 2;
        	if((mid - 1 >= 0 && num[mid - 1] > num[mid]) || mid == 0)
        		return num[mid];
        	if(num[start] < num[mid]) {
        		if(num[start] < num[end - 1])
        			end = mid;
        		else
        			start = mid + 1;
        	}
        	else 
        		end = mid;
        }
        return 0;
    }
};