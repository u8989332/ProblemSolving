using System;

namespace LeetCode821
{
	public class Solution {
		private const int MAXINT = 99999;
		public int[] ShortestToChar(string S, char C) {
			int[] ans = new int[S.Length];
			
			int prev = -MAXINT;
			for(int i = 0 ; i < S.Length;++i){
				if(S[i] == C){
					prev = i;
				}
				
				ans[i] = i - prev;
			}
			
			prev = MAXINT;
			for(int i = S.Length - 1 ; i >= 0;--i){
				if(S[i] == C){
					prev = i;
				}
				
				ans[i] = Math.Min(ans[i], prev - i);
			}
			
			return ans;
		}
	}
	
	public class Program
	{
		public static void Main()
		{
			Solution sol = new Solution();
			int[] ans = sol.ShortestToChar("loveleetcode" , 'e');
			foreach(int num in ans)
			{
				Console.WriteLine(num);
			}

			Console.Read();
		}
	}
}