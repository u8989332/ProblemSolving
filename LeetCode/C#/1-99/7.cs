using System;
 
namespace LeetCode7
{
	public class Solution {
	    public int Reverse(int x) {
	        long ans = 0;
	        while(x != 0){
	            ans = ans * 10 + (x % 10);
	            x /= 10;
	        }
 
	        return Math.Abs(ans) > Int32.MaxValue ? 0 : (int)ans;
	    }
	}
 
	public class Program
	{
		public static void Main()
		{
			Solution sol = new Solution();
			Console.WriteLine(sol.Reverse(123));
			Console.WriteLine(sol.Reverse(-123));
			Console.WriteLine(sol.Reverse(1234567899));
			Console.Read();
		}
	}
}