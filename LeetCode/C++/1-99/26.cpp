#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int count = 0 ;
        int originSize = nums.size();
        for(int i = 1 ; i < originSize;++i){
            if(nums[i] == nums[i-1]){
                count++;
            }
            nums[i-count] = nums[i];
        }
        
        return originSize - count;
    }
};

int main() {
	Solution sol;
	vector<int> nums{1,1,2};
	int len = sol.removeDuplicates(nums);
	for(int i = 0 ; i < len;++i){
		cout << " " << nums[i];
	}
	cout << endl;
	return 0;
}