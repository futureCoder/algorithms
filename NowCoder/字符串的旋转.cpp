class StringRotation {
public:
	void reverse(string &str, int start, int end) {
		while(start < end) {
			swap(str[start++], str[end--]);
		}
	}
    string rotateString(string A, int n, int p) {
        if(p >= n)
        	return A;
        reverse(A, 0, p);
        reverse(A, p + 1, n - 1);
        reverse(A, 0, n - 1);
        return A;
    }
};