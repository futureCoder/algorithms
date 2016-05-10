class Solution {
public:
	int trap(const vector<int>& A) {
		const int n = A.size();
		stack<pair<int, int>> s;
		int water = 0;
		for (int i = 0; i < n; ++i) {
			int height = 0;
			while (!s.empty()) {	//将栈里比当前元素矮或等高的元素全部处理掉
				int bar = s.top().first;
				int pos = s.top().second;
				// bar,height ,a[i]三者夹成的凹陷
				water += (min(bar, A[i]) - height) * (i - pos - 1);
				height = bar;
				if (A[i] < bar)	//碰到了比当前元素高的,跳出循环
					break;
				else
					s.pop();	//弹出栈顶,因为该元素处理完了,不再需要了
			}
			s.push(make_pair(A[i], i));
		}
		return water;
	}
};