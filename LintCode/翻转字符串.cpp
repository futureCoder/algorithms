class Solution {
public:
    /**
     * @param s : A string
     * @return : A string
     */
    string reverseWords(string s) {
        if(s.empty())
        	return s;
        int curIdx = 0, start, end, len = s.size();
        for(start = 0, end = 0;end < s.size();) {
        	while(start < len && s[start] == ' ')
        		++start;
        	end = start;
        	while(end < len && s[end] != ' ')
        		++end;
        }
    }
    void reverse(string &s, int targetIdx, int start, int end) {

    }
};