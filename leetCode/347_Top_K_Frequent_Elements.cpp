class Solution {
public:
	template<typename ForwardIterator, typename T>
	void heapAdjust(ForwardIterator root, ForwardIterator target, ForwardIterator last) {
		ForwardIterator child = next(root, distance(root, target) * 2 + 1);
		if(child >= last) return;
		for(auto tmp = *target; target < last; target = child)
		{
			if(next(child) < last && child->second < next(child)->second) child = next(child);
			if(target->second < child->second)
				swap(*target,*child);
		}
	}
	void heapsort(ForwardIterator root, ForwardIterator last, T k) {
		auto cur = next(root,distance(root, last) / 2 - 1);
		for(;cur >= root;cur = prev(cur))
			heapAdjust(root, cur, last);
		cur = prev(last);
		while(cur > root && k--)
		{
			swap(*root, *cur);
			cur = prev(cur);
			heapAdjust(root, cur, last);
		}
	}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> mymap;
        for(auto i : nums)
        	++mymap[i];
        heapsort(mymap.begin(), mymap.end(), k)
        vector<int> ret;
        for(auto p = mymap.end();k--;)
        	ret.push_back(p->first);
        return ret;
    }
};