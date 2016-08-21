class Solution {
public:
    /**
     * @param nums: A list of integers.
     * @return: The maximum number inside the window at each moving.
     */
    vector<int> maxSlidingWindow(vector<int> &nums, int k) {
        deque<int> maxQ;
        for(int i = 0; i < k - 1; ++i) {
        	while(!maxQ.empty() && nums[i] >= nums[maxQ.back()])
        		maxQ.pop_back();
        	maxQ.push_back(i);
        }
        vector<int> ret;
        for(int i = k - 1; i < nums.size(); ++i) {
        	while(!maxQ.empty() && nums[i] >= nums[maxQ.back()])
        		maxQ.pop_back();
        	while(!maxQ.empty() && maxQ.front() <= i - k)
        		maxQ.pop_front();
        	maxQ.push_back(i);
        	ret.push_back(nums[maxQ.front()]);
        }
        return ret;
    }
};
