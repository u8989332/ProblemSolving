using System;
using System.Collections.Generic;
namespace LeetCode66
{
	public class Solution {
	    public int[] PlusOne(int[] digits) {
	        int curAddDigit = 1;
	        int nextAddDigit = 0;
	        List<int> ans = new List<int>(digits);
 
	        for(int i = digits.Length - 1;i >= 0;--i){
	            nextAddDigit = (curAddDigit + ans[i]) / 10;
	            ans[i] = (curAddDigit + ans[i]) % 10;
	            curAddDigit = nextAddDigit;
	            if(curAddDigit == 0){
	                break;
	            }
	        }
 
	        if(nextAddDigit == 1){
	            ans.Insert(0, 1);
	        }
 
	        return ans.ToArray();
	    }
	}
 
	public class Program
	{
		public static void Main()
		{
			Solution sol = new Solution();
			int[] digits = new int[]{1,2,3};
			int[] ans = sol.PlusOne(digits);
			foreach(int num in ans){
				Console.Write(" " + num);
			}
 
			Console.Read();
		}
	}
}