#include <iostream>
#include <vector>
#define MAXINT 99999
using namespace std;

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> ans(S.length());
        
        int prev = -MAXINT;
        for(int i = 0 ; i < S.length();++i){
            if(S[i] == C){
                prev = i;
            }
            
            ans[i] = i - prev;
        }
        
        prev = MAXINT;
        for(int i = S.length() - 1 ; i >= 0;--i){
            if(S[i] == C){
                prev = i;
            }
            
            ans[i] = min(ans[i], prev - i);
        }
        
        return ans;
    }
};

int main()
{
    Solution s;
	vector<int> ans = s.shortestToChar("loveleetcode", 'e');
	for(int num : ans){
		cout << num << endl;
	}

    return 0;
}
