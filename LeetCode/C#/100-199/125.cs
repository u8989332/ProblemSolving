using System;

namespace LeetCode125
{
	public class Solution {
	    private int GetAlphanumericCommonIndex(char c){
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
	    
	    public bool IsPalindrome(string s) {
	        int n = s.Length;
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
	            
	            left = GetAlphanumericCommonIndex(s[i]);
	            right = GetAlphanumericCommonIndex(s[j]);
	
	            
	            if(left != right){
	                isOk = false;
	                break;
	            }
	            
	            ++i;
	            --j;
	        }
	        
	        return isOk;
	    }
	}
	
	public class Program
	{
		public static void Main()
		{
			Solution sol = new Solution();
			Console.WriteLine(sol.IsPalindrome("A man, a plan, a canal: Panama"));
			Console.WriteLine(sol.IsPalindrome("race a car"));
			Console.Read();
		}
	}
}
