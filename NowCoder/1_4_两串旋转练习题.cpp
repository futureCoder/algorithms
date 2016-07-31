class Rotation {
public:
	void reverse(string &str, int start, int end) {
		while(start < end) {
			swap(str[start++], str[end--]);
		}
	}
    bool chkRotation(string A, int lena, string B, int lenb) {
    	if(0 == lena && 0 == lenb)
    		return true;
        if(lena != lenb)
        	return false;
        auto target = A[0];
        int idx = 0, count = 0;
        while(idx < lenb) {
        	if(target == B[idx])
        	{
        		++count;
        	}
        	++idx;
        }
        reverse(B, 0, idx - 1);
        reverse(B, idx, lenb - 1);
        reverse(B, 0, lenb - 1);
        if(A == B)
        	return true;
        return false;
    }
};