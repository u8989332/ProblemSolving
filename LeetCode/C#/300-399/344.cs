using System;

namespace LeetCode344
{
	public class Solution {
	    public void ReverseString(char[] s) {
	        int mid = s.Length / 2;
	        for(int i = 0 ; i < s.Length / 2;++i){
	            char a = s[i];
	            s[i] = s[s.Length - i - 1];
	            s[s.Length-i-1] = a;
	        }
	    }
	}
	
	public class Program
	{
		public static void Main()
		{
			Solution sol = new Solution();
			char[] s = new char[]{'h', 'e', 'l', 'l', 'o'};
			sol.ReverseString(s);
			foreach(char c in s)
			{
				Console.Write(c + " ");
			}
			
			Console.Read();
		}
	}
}
