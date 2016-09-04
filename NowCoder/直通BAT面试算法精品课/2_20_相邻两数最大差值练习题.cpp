class Gap {
public:
	int maxGap(vector<int> A, int n) {
		int _min = INT_MAX, _max = INT_MIN;
		for (int i = 0; i < n; ++i) {
			_min = min(_min, A[i]);
			_max = max(_max, A[i]);
		}
		vector<bool> hasNum(n + 1, false);
		vector<int> minBucket(n + 1), maxBucket(n + 1);
		for (int i = 0; i < n; ++i) {
			int idx = getBucketIdx(A[i], _min, _max, n);
			minBucket[idx] = hasNum[idx] ? min(minBucket[idx], A[i]) : A[i];
			maxBucket[idx] = hasNum[idx] ? max(maxBucket[idx], A[i]) : A[i];
			hasNum[idx] = true;
		}
		int i = 0;
		int last;
		int ret = INT_MIN;
		while (i <= n) {
			if (hasNum[i]) {
				last = i++;
				break;
			}
		}
		while (i <= n) {
			if (hasNum[i]) {
				ret = max(minBucket[i] - maxBucket[last], ret);
				last = i;
			}
			++i;
		}
		return ret;
	}
private:
	int getBucketIdx(long num, long _min, long _max, long n) {
		return (int)((num - _min) * n / (_max - _min));
	}
};