class Solution {
public:
	template<typename ForwardIterator>
	void reverseWord(ForwardIterator first, ForwardIterator last) {
		last = prev(last);
		while(first != last)
			swap(first++, last--);
	}
    void reverseWords(string &s) {
        auto first = s.begin(), last = s.end();
        reverseWord(first, last);
        for(last = s.begin(); last != s.end();)
        {
        	first = last;
        	while(last != s.end() && *last != ' ') ++last;
        	reverseWord(first, last);
        }
        return ;
    }
};