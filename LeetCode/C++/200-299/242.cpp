#include <iostream>
#include <vector>
using namespace std;
 
class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> sCheck(26);
        vector<int> tCheck(26);
        for(int i = 0 ; i < s.length();++i){
            sCheck[s[i] - 'a']++;
        }
 
        for(int i = 0 ; i < t.length();++i){
            tCheck[t[i] - 'a']++;
        }
 
        bool isSame = true;
        for(int i = 0 ; i < 26;++i){
            if(sCheck[i] != tCheck[i]){
                isSame = false;
                break;
            }
        }
 
        return isSame;
    }
};
 
int main() {
	Solution sol;
	cout << sol.isAnagram("anagram", "nagaram") << endl;
	return 0;
}