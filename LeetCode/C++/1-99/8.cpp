#include <iostream>
#include <cstdlib>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int n = s.length();
        bool isPositive = true;
        int i;
        for(i = 0 ; i < n;++i){
            if(s[i] != ' ' && s[i] != '+' && s[i] != '-' && !isdigit(s[i])){
                return 0;
            }
            else if(s[i] == ' '){
                continue;
            }
            else if(s[i] == '+'){
                ++i;
                break;
            }
            else if(s[i] == '-'){
                ++i;
                isPositive = false;
                break;
            }
            else{
                break;
            }
        }

        long long ans = 0;
        for(int j = i; j < n;++j){
            if(!isdigit(s[j])){
                break;
            }

            ans = ans * 10 + (isPositive ? (s[j] - '0') : -(s[j] - '0'));

            if(ans > INT_MAX){
                return INT_MAX;
            }
            else if(ans < INT_MIN){
                return INT_MIN;
            }
        }

        return (int) ans;
    }
};

int main()
{
    Solution sol;
    cout << sol.myAtoi("   -42") << endl;
    cout << sol.myAtoi("4193 with words") << endl;
    cout << sol.myAtoi("words and 987") << endl;
    cout << sol.myAtoi("-91283472332") << endl;
    return 0;
}