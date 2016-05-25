class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,bool> visited;
        for(auto i : nums)
        	if(!visited[i])
        		visited[i] = true;
        	else
        		return true;
        return false;
    }
};