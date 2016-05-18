class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.size();
        for(int i = 0;i < len; ++i)
        {
        	switch(s[i])
        	{
        		case ')' : if(st.empty() || st.top() != '(') return false; else st.pop(); break;
        		case ']' : if(st.empty() || st.top() != '[') return false; else st.pop(); break;
        		case '}' : if(st.empty() || st.top() != '{') return false; else st.pop(); break;
        		default : st.push(s[i]);break;
        	}
        }
        if(!st.empty()) return false;
        return true;
    }
};