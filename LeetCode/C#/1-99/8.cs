using System;

namespace LeetCode8
{
	public class Solution {
	    public int MyAtoi(string s) {
	        int n = s.Length;
	        bool isPositive = true;
	        int i;
	        for(i = 0 ; i < n;++i){
	            if(s[i] != ' ' && s[i] != '+' && s[i] != '-' && !Char.IsDigit(s[i])){
	                return 0;
	            }
	            else if(s[i] == ' '){
	                continue;
	            }
	            else if(s[i] == '+'){
	                ++i;
	                break;
	            }
	            else if(s[i] == '-'){
	                ++i;
	                isPositive = false;
	                break;
	            }
	            else{
	                break;
	            }
	        }
	        
	        long ans = 0;
	        for(int j = i; j < n;++j){
	            if(!Char.IsDigit(s[j])){
	                break;
	            }
	            
	            ans = ans * 10 + (isPositive ? (s[j] - '0') : -(s[j] - '0'));
	            
	            if(ans > Int32.MaxValue){
	                return Int32.MaxValue;
	            }
	            else if(ans < Int32.MinValue){
	                return Int32.MinValue;
	            }
	        }
	        
	        return (int) ans;
	    }
	}
	public class Program
	{
		public static void Main()
		{
			Solution sol = new Solution();
			Console.WriteLine(sol.MyAtoi("   -42"));
		    Console.WriteLine(sol.MyAtoi("4193 with words"));
		    Console.WriteLine(sol.MyAtoi("words and 987"));
		    Console.WriteLine(sol.MyAtoi("-91283472332"));
		}
	}
}
