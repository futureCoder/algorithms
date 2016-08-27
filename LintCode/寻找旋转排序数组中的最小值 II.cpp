class Solution {
public:
    /**
     * @param num: the rotated sorted array
     * @return: the minimum number in the array
     */
    int findMin(vector<int> &num) {
        int start = 0, end = num.size();
        while(start < end) {
        	while(start + 1 < end && num[start + 1] == num[start])
        		++start;
        	while(end - 2 > start && num[end - 2] == num[end - 1])
        		--end;
        	int mid = start + (end - start) / 2;
        	if((mid > 0 && num[mid - 1] > num[mid]) || mid == start)
        		return num[mid];
        	if(num[start] <= num[mid]) {
        		if(num[mid] <= num[end - 1])
        			end = mid;
        		else
        			start = mid + 1;
        	}
        	else {
        		if(num[mid] <= num[end - 1])
        			end = mid;
        		else
        			start = mid + 1;
        	}
        }
        return -1;
    }
};