#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int curAddDigit = 1;
        int nextAddDigit = 0;
        vector<int> ans(digits.size());
        for(int i = digits.size() - 1;i >= 0;--i){
            ans[i] = digits[i];
        }
        for(int i = digits.size() - 1;i >= 0;--i){
            nextAddDigit = (curAddDigit + ans[i]) / 10;
            ans[i] = (curAddDigit + ans[i]) % 10;
            curAddDigit = nextAddDigit;
            if(curAddDigit == 0){
                break;
            }
        }
 
        if(nextAddDigit == 1){
            ans.insert(ans.begin(), 1);
        }
 
        return ans;
    }
};
 
int main() {
	Solution sol;
	vector<int> digits{1,2,3};
	vector<int> ans = sol.plusOne(digits);
	for(int num : ans){
		cout << num << " ";
	}
	return 0;
}