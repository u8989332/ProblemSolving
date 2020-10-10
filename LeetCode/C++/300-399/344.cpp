#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    void reverseString(vector<char>& s) {
        for(int i = 0 ; i < s.size() / 2;++i){
            char temp = s[i];
            s[i] = s[s.size()-i-1];
            s[s.size()-i-1] = temp;
        }
    }
};
 
int main() {
	vector<char> s{'h','e','l','l','o'};
	Solution sol;
	sol.reverseString(s);
	for(char c : s){
		cout << c << " ";
	}
	return 0;
}