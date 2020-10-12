#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    int firstUniqChar(string s) {
        vector<vector<int>> checkChars(26);
        for(int i = 0 ; i < s.length();++i){
            checkChars[s[i] - 'a'].push_back(i);
        }
 
        bool isUniqueFind = false;
        int minIndex = 99999999;
        for(int i = 0 ; i < 26;++i){
            if(checkChars[i].size() == 1){
                isUniqueFind = true;
                if(checkChars[i][0] < minIndex){
                    minIndex = checkChars[i][0];
                }
            }
        }
 
        if(isUniqueFind){
            return minIndex;
        }
        else{
            return -1;
        }
    }
};
 
int main() {
	Solution sol;
	cout << sol.firstUniqChar("leetcode") << endl;
	cout << sol.firstUniqChar("aabbcc") << endl;
	cout << sol.firstUniqChar("abcabcd") << endl;
	return 0;
}