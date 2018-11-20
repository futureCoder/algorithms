#include<iostream>
#include<set>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    	set<int> value;
    	value.insert(nums.front());
		int i=1,f=-1,r;
		while(i<nums.size()){
    		if(value.find(target - nums.at(i))==value.end())	value.insert(nums.at(i));
    		else {
    			f=i;r=value.find(target - nums.at(i));break;
			}
		}
		if(f>r){
			int temp = f;
			f=r;
			r=temp;
		}
		if(f==-1) cout<<"error";
		else cout<<f<<" "<<r<<endl;
    }
};

int main(){
	Solution s;
	int a[4] = {2, 7, 11, 15}
	vector<int> vet(a,a+4);
	int target = 9;
	s.twoSum(vet,target);
}
