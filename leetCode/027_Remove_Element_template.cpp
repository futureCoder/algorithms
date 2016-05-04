class Solution {
public:
	int removeElement(vector<int>& nums, int target) 
	{
		return distance(nums.begin(), remove(nums.begin(), nums.end(), target));
	}
};