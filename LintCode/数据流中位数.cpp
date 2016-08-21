class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The median of numbers
     */
     vector<int> medianII(vector<int> &nums) {
        numOfNum = 0;
        vector<int> ret;
        for(auto i : nums) {
            insertVal(i);
            ret.push_back(getMedian());
        }
        return ret;
    }
    void insertVal(int val) {
        max_queue.push(val);
        if((numOfNum & 0x1) == 0) {
            if(min_queue.empty()) {
                ++numOfNum;
                return;
            }
            if(max_queue.top() > -min_queue.top()) {
                int maxNum = max_queue.top(), minNum = -min_queue.top();
                max_queue.pop();
                min_queue.pop();
                max_queue.push(minNum);
                min_queue.push(-maxNum);
            }
        }
        else {
            min_queue.push(-max_queue.top());
            max_queue.pop();
        }
        ++numOfNum;
    }
    int getMedian() {
        return max_queue.top();
    }
private:
    priority_queue<int> max_queue, min_queue;
    int numOfNum;

};
