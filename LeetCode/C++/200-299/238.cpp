#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        
        ans[0] = 1;
        for(int i = 1; i < n;++i){
            ans[i] = nums[i-1] * ans[i-1];
        }
        
        int R = 1;
        for(int i = n - 1;i >= 0;--i){
            ans[i] = ans[i] * R;
            R *= nums[i];
        }
        
        return ans;
    }
};

int main() {
	vector<int> nums{1,2,3,4};
	Solution sol;
	vector<int> ans = sol.productExceptSelf(nums);
	for(int num : ans){
		cout << " " << num;
	}
	cout << endl;
	return 0;
}