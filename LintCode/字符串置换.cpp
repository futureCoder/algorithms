class Solution {
public:
    /**
     * @param A a string
     * @param B a string
     * @return a boolean
     */
    bool stringPermutation(string& A, string& B) {
        map<char, int> mymap;
        for(auto i : A)
        	++mymap[i];
        for(auto i : B)
        	--mymap[i];
        for(auto i : mymap)
        	if(i.second != 0)
        		return false;
        return true;
    }
};