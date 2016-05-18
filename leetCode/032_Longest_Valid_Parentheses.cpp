class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        int len = s.size(),ret = 0, index = -1;
        for(int i = 0; i < len; ++i)
        {
        	if(s[i] == ')')
        	{
        		if(st.empty()) index = i;
        		else
        		{
        			st.pop();
        			if(st.empty())
        			{
        				ret = max(ret, i - index);
        			}
        			else
        			{
        				ret = max(ret, i - st.top());
        			}
        		}
        	}
        	else st.push(i);
        }
        return ret;
    }
};