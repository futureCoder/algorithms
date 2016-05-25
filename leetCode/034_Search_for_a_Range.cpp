class Solution {
public:
	template<typename ForwardIterator, typename T>
	ForwardIterator lower_bound(ForwardIterator first, ForwardIterator last, T target) {
		while(first != last)
		{
			auto mid = next(first, distance(first,last) / 2);
			if(*mid < target) first = ++mid;
			else last = mid;
		}
		return first;
	}
	template<typename ForwardIterator, typename T>
	ForwardIterator upper_bound(ForwardIterator first, ForwardIterator last, T target) {
		while(first!=last)
		{
			auto mid = next(first, distance(first, last) / 2);
			if(*mid <= target) first = ++mid;
			else last = mid;
		}
		return first;
	}
    vector<int> searchRange(vector<int>& nums, int target) {
        auto lower = lower_bound(nums.begin(), nums.end(), target);
        auto upper = upper_bound(lower, nums.end(), target);
        std::vector<int> ret;
        if(lower == nums.end() || *lower != target)
        	return vector<int>(2,-1);
        return vector<int> {distance(nums.begin(), lower), distance(nums.begin(), prev(upper))};
    }
};