#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for(int i = 0 ; i < nums.size();++i){
            ans ^= nums[i];
        }
        
        return ans;
    }
};

int main() {
	
	vector<int> nums{1,2,4,4,2};
	Solution sol;
	cout << sol.singleNumber(nums) << endl;
	return 0;
}