class Solution {
public:
    /**
     * @param str: a string
     * @param offset: an integer
     * @return: nothing
     */
    void rotateString(string &str,int offset){
    	if(str.size() == 0 || offset < 1)
    		return ;
    	int strEnd = str.size() - 1;
    	offset %= str.size();
    	reverse(str, strEnd - offset + 1, strEnd);
    	reverse(str, 0, strEnd - offset);
        reverse(str, 0, strEnd);
    }
    void reverse(string &str, int start, int end) {
    	while(start < end)
    		swap(str[start++], str[end--]);
    }
};
