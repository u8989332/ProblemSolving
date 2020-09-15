#include <iostream>
#include <stack>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        stack<int> st;
        int size = T.size();
        vector<int> ans = vector<int>(size, 0);

        for(int i = 0 ; i < size;++i){
            while(!st.empty()){
                if(T[i] > T[st.top()]){
                    ans[st.top()] = i - st.top();
                    st.pop();
                }
                else{
                    break;
                }
            }

            st.push(i);
        }
        
        return ans;
    }
};


int main()
{
	vector<int> T{73, 74, 75, 71, 69, 72, 76, 73}; 
	Solution sol;
	vector<int> ans = sol.dailyTemperatures(T);
    
	for(int i = 0 ; i < ans.size();++i){
		cout << ans[i] << endl;
	}

    return 0;
}
