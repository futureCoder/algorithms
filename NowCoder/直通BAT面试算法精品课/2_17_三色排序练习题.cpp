class ThreeColor {
public:
	vector<int> sortThreeColor(vector<int> A, int n) {
		if (A.empty() || n < 2)
			return A;
		int first = -1, last = n, i = 0;
		while (i < last) {
			if (0 == A[i])
				swap(A[i++], A[++first]);
			else if (2 == A[i])
				swap(A[i], A[--last]);
			else
				++i;
		}
		return A;
	}
};