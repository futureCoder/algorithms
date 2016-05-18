class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int a,b,ret;
        for(auto s : tokens)
        {
            if(s.size() == 1 && string("+-*/").find(s) != string::npos)
        	{
        	    switch(s[0])
            	{
            		case '+' : b = st.top();st.pop();a = st.top();st.pop();st.push(a + b); break;
            		case '-' : b = st.top();st.pop();a = st.top();st.pop();st.push(a - b); break;
            		case '*' : b = st.top();st.pop();a = st.top();st.pop();st.push(a * b); break;
            		case '/' : b = st.top();st.pop();a = st.top();st.pop();st.push(a / b); break;
            	}
        	}
        	else
        	{
        	    st.push(stoi(s));
        	}
        }
        ret = st.top();
        st.pop();
        return ret;
    }
};