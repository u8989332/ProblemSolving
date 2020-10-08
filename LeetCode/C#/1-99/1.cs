using System;
using System.Collections.Generic;

namespace LeetCode1
{
	public class Solution {
	    public int[] TwoSum(int[] nums, int target) {
	        Dictionary<int, int> repeat = new Dictionary<int, int>();
	        int[] ans = new int[2];
	        for(int i = 0;i < nums.Length;++i){
	            if(repeat.ContainsKey(nums[i])){
	                ans[0] = repeat[nums[i]];
	                ans[1] = i;
	                break;
	            }
	            repeat[target - nums[i]] = i;
	        }
	        
	        return ans;
	    }
	}
	
	public class Program
	{
	
		public static void Main()
		{
			int[] nums = new int[]{2,7,11,15};
			Solution sol = new Solution();
			int[] ans = sol.TwoSum(nums, 9);
			foreach(int num in ans)
			{
				Console.Write(num + " ");
			}
			Console.Read();
		}
	}
}