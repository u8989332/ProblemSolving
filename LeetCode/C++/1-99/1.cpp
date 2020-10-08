#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> repeat;
        vector<int> ans;
        for(int i = 0;i < nums.size();++i){
            if(repeat.count(nums[i])){
                ans.push_back(repeat[nums[i]]);
                ans.push_back(i);
                break;
            }
            repeat[target - nums[i]] = i;
        }
        
        return ans;
    }
};

int main() {
	vector<int> nums{2,7,11,15};
	Solution sol;
	vector<int> ans = sol.twoSum(nums, 9);
	for(int num : ans){
		cout << num << " ";
	}
	return 0;
}
@u8989332
 