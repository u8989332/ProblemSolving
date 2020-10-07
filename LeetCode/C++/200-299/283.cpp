#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int lastZeroIndex = 0;
        for(int i = 0 ; i < n;++i){
            if(nums[i] != 0){
                swap(nums[i], nums[lastZeroIndex++]);
            }
        }
    }
};

int main() {
	Solution sol;
	vector<int> nums{0,1,0,3,12};
	sol.moveZeroes(nums);
	for(int num : nums){
		cout << num << " ";
	}
	return 0;
}