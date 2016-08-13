class Solution {
public:
	vector<int> diffWaysToCompute(const string& str, int start, int end) {
		vector<int> ret;
		int curStart = start, curEnd = start;
		while(curStart < end) {
			curEnd = curStart;
			while(curEnd < end && '0' <= str[curEnd] && str[curEnd] <= '9') ++curEnd;
			if(curEnd == end && curStart == start) {
				ret.push_back(std::stoi(str.substr(curStart, curEnd - curStart)));
				return ret;
			}
			if(curEnd != end) {
			char op = str[curEnd];
			vector<int> left = diffWaysToCompute(str, start, curEnd);
			vector<int> right;
			if(curEnd != end)
				right = diffWaysToCompute(str, curEnd + 1, end);
			for(auto i : left)
				for(auto j : right) {
					switch(op) {
						case '+' : ret.push_back(i + j);break;
						case '-' : ret.push_back(i - j);break;
						case '*' : ret.push_back(i * j);break;
						case '/' : ret.push_back(i / j);break;
					}
				}
			}
			curStart = curEnd + 1;
		}
		return ret;
	}
    vector<int> diffWaysToCompute(string input) {
        return diffWaysToCompute(input, 0, input.size());
    }
};