class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        return distance(nums.begin(), lower);
    }
	template<typename ForwardIterator, typename T>
	ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T target) {
		while(first != last)
		{
			auto mid = next(first, distance(first, last) / 2);
			if(*mid < target) first = ++mid;
			else last = mid;
		}
		return first;
	}
};