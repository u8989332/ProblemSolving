using System;

namespace LeetCode238
{
	public class Program
	{
		public class Solution {
			public int[] ProductExceptSelf(int[] nums) {
				int n = nums.Length;
				int[] ans = new int[n];

				ans[0] = 1;
				for(int i = 1; i < n;++i){
					ans[i] = nums[i-1] * ans[i-1];
				}

				int R = 1;
				for(int i = n - 1;i >= 0;--i){
					ans[i] = ans[i] * R;
					R *= nums[i];
				}

				return ans;
			}
		}

		public static void Main()
		{
			Solution sol = new Solution();
			int[] nums = new int[]{1,2,3,4};
			int[] ans = sol.ProductExceptSelf(nums);
			foreach(int num in ans)
			{
				Console.Write(" " + num);
			}
			Console.WriteLine("");
			Console.Read();
		}
	}
}