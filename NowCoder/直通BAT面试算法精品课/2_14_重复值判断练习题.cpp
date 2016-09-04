class Checker {
public:
    bool checkDuplicate(vector<int> a, int n) {
        for(int i = n / 2 - 1; i >= 0; --i)
            if(heapAdjust(a, i, n))
                return true;
        for(int i = n - 1; i > 0; --i) {
            swap(a[0], a[i]);
            if(heapAdjust(a, 0, i))
                return true;
            if(a[0] == a[i])
                return true;
        }
        return false;
    }
	bool heapAdjust(vector<int> &a, int i, int len) {
		int nChild;
		for (int nTmp = a[i]; 2 * i + 1 < len; i = nChild) {
			nChild = 2 * i + 1;
			if (nChild + 1 < len) {
                if(a[nChild + 1] == a[nChild])
                    return true;
                else if(a[nChild + 1] > a[nChild])
                    ++nChild;
            }
            if(a[i] == a[nChild])
                return true;
			if (a[i] < a[nChild]) {
				a[i] = a[nChild];
				a[nChild] = nTmp;
			}
			else
				return false;
		}
        return false;
	}
};