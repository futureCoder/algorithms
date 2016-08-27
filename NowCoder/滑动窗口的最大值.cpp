class Solution {
public:
    vector<int> maxInWindows(const vector<int>& num, unsigned int size)
    {
        vector<int> ret;
    	if(num.empty())
    		return ret;
        deque<int> q;
        for(int i = 0; i < size - 1 && i < num.size(); ++i) {
        	while(!q.empty() && num[i] > num[q.back()])
        		q.pop_back();
        	q.push_back(i);
        }
        for(int i = size - 1; i < num.size(); ++i) {
        	while(!q.empty() && num[i] > num[q.back()])
        		q.pop_back();
        	while(!q.empty() && q.front() < i - size + 1)
        		q.pop_front();
        	q.push_back(i);
        	ret.push_back(num[q.front()]);
        }
        return ret;
    }
};