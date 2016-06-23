class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        int start = 1, end = 1;
        if(path.size() > 1 && path[path.size() - 1] == '/')
            path.pop_back();
        while(start < path.size()) {
            while(start < path.size() && path[start] == '/') ++start;
            if(start == path.size())
                break;
        	if((end = path.find("/", start)) == std::string::npos)
        		end = path.size();
        	string tmp(path.substr(start, end - start));
    		if(tmp == "..")
    			if(st.empty()) ;
    			else st.pop_back();
    		else if(tmp == ".")
    			;
        	else
        		st.push_back(tmp);
        	start = end + 1;
        }
        if(st.empty())
            return string("/");
        string ret;
        for(auto i : st)
        	ret += ("/" + i);
        return string(ret);
    }
};