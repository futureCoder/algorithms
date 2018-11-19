#include<iostream>
#include<map>
#include<set>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
     map<int,int>   hash_map;
     vector<int> ret;
     int i=0,v1,v2;
	 hash_map.insert(nums.front(),i);
	 while(++i<nums.size()){
	 	if(hash_map.find(target - nums.at(i))==hash_map.end()) hash_map.insert(nums.at(i),i);
	 	else {
	 		v1=i;
	 		v2=hash_map[target - nums.at(i)];
	 		if(v1>v2){
	 			int tmp = v1;
	 			v1 = v2;
	 			v2 = tmp;
			 }
			 ret.push_back(v1);
			 ret.push_back(v2);
			 
		 }
	 }
    return ret; 
    }
};

int main(){
	int a[4]={2, 7, 11, 15};
	vector<int> numbers(a,a+4);
	int target=9;
	Solution s;
	vector<int> answer = s.twoSum(numbers,target);
}
