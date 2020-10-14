#include <iostream>
using namespace std;

class Solution {
private: 
    int getAlphanumericCommonIndex(char c){
        int index;
        if(c >= 'a' && c <= 'z'){
            index = c - 'a';
        }
        else if(c >= 'A' && c <= 'Z'){
            index = c - 'A';
        }
        else{
            index = c - '0' + 26;
        }
        
        return index;
    }
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int i = 0, j = n-1;
        bool isOk = true;
        int left, right;
        while(i < j){
            while(i < n && !(s[i] >= '0' && s[i] <= '9') && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z')){
                ++i;
            }
            
            while(j >= 0 && !(s[j] >= '0' && s[j] <= '9') && !(s[j] >= 'a' && s[j] <= 'z') && !(s[j] >= 'A' && s[j] <= 'Z')){
                --j;
            }

            if(i >= j){
                break;
            }
            
            left = getAlphanumericCommonIndex(s[i]);
            right = getAlphanumericCommonIndex(s[j]);

            
            if(left != right){
                isOk = false;
                break;
            }
            
            ++i;
            --j;
        }
        
        return isOk;
    }
};

int main() {
	Solution sol;
	cout << sol.isPalindrome("A man, a plan, a canal: Panama") << endl;
	cout << sol.isPalindrome("race a car") << endl;
	return 0;
}