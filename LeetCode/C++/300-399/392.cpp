#include <iostream>
#include <string>
using namespace std;
 
 
class Solution {
public:
    bool isSubsequence(string s, string t) {
        bool isSub = false;
        int i,j;
        for(i = 0, j = 0; i < s.length() && j < t.length();){
            if(s[i] == t[j]){
                i++;
                j++;
            }
            else{
                j++;
            }
        }
 
        if(i >= s.length()){
            isSub = true;
        }
 
        return isSub;
    }
};
 
int main() {
	Solution sol;
	cout << sol.isSubsequence("abc", "ahbgdc") << endl;
	return 0;
}