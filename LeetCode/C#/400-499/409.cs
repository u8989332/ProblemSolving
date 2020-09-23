using System;

namespace LeetCode409
{
	public class Solution {
		public int LongestPalindrome(string s) {
			int[] letters = new int[128];
			foreach(char c in s){
				letters[(int)c]++;
			}

			int ans = 0;
			for(int i = 0 ; i < 128;++i){
				int curLen = letters[i];
				if(letters[i] % 2 == 1){
					curLen--;
				}

				ans+=curLen;
				if(ans % 2 == 0 && letters[i] % 2 == 1){
					ans++;
				}
			}
			return ans;
		}
	}
	
	public class Program
	{
		public static void Main()
		{
			Solution sol = new Solution();
			Console.WriteLine(sol.LongestPalindrome("abccccdd"));
			Console.Read();
		}
	}
}