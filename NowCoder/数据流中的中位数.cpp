class Solution {
public:
    void Insert(int num)
    {
    	left.push(num);
    	++cnt;
    	if(cnt & 0x1) {
    		if(right.empty()) {
    			return ;
    		}
    		if(left.top() > right.top()) {
    			num = left.top();
    			left.pop();
    			left.push(right.top());
    			right.pop();
    			right.push(num);
    		}
    	}
    	else {
    		right.push(left.top());
    		left.pop();
    	}
    }

    double GetMedian()
    {
    	if(cnt == 0)
    		return 0;
    	if(cnt & 0x1)
    		return left.top();
    	return (left.top() + right.top()) / 2.0;
    }
private:
	priority_queue<int> left;
	priority_queue<int, vector<int>,greater<int>> right;
	int cnt = 0;
};