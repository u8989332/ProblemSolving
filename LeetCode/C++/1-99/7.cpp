#include <iostream>
#include <cmath>
#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long ans = 0;
        while(x != 0){
            ans = ans * 10 + (x % 10);
            x /= 10;
        }
        
        return fabs(ans) > INT_MAX ? 0 : ans;
    }
};

int main() {
	Solution sol;
	cout << sol.reverse(123) << endl;
	cout << sol.reverse(-123) << endl;
	cout << sol.reverse(1234567899) << endl;
	return 0;
}