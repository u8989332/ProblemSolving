public class Solution {
    private static string ReverseString(string s)
    {
        char[] array = s.ToCharArray();
        Array.Reverse(array);
        return new string(array);
    }
    
    public string RemoveDuplicates(string S) {
        Stack<char> st = new Stack<char>();
        for(int i = 0 ; i < S.Length;++i){
            if(st.Count == 0 || st.Peek() != S[i]){
                st.Push(S[i]);
            }
            else{
                st.Pop();
            }
        }
        
        StringBuilder ans = new StringBuilder();
        while(st.Count > 0){
            ans.Append(st.Peek());
            st.Pop();
        }
        
        return ReverseString(ans.ToString());
    }
}