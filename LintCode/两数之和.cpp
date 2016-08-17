class Solution {
public:
    /*
     * @param numbers : An array of Integer
     * @param target : target = numbers[index1] + numbers[index2]
     * @return : [index1+1, index2+1] (index1 < index2)
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        map<int, int> mymap;
        vector<int> ret;
        for(int i = 0; i < nums.size(); ++i) {
        	if(mymap.find(nums[i]) != mymap.end()) {
        		ret.push_back(mymap[nums[i]]);
        		ret.push_back(i + 1);
        	}
        	mymap[target - nums[i]] = i + 1;
        }
        return ret;
    }
};
