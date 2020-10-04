#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> repeat;
        for(int i = 0; i < nums.size();++i){
            if(repeat.count(nums[i])){
                return true;
            }
            
            repeat.insert(nums[i]);
        }
        
        return false;
    }
};

int main() {
	vector<int> nums{1,2,3,1};
	Solution sol;
	cout << sol.containsDuplicate(nums) << endl;
	return 0;
}