class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for(int i = 0 ; i < S.length();++i){
            if(st.empty() || st.top() != S[i]){
                st.push(S[i]);
            }
            else{
                st.pop();
            }
        }
        
        string ans = "";
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};