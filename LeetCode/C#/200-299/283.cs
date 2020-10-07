using System;
 
namespace LeetCode283
{
	public class Program
	{
		public class Solution {
		    public static void Swap<T> (ref T lhs, ref T rhs) {
		        T temp = lhs;
		        lhs = rhs;
		        rhs = temp;
		    }
 
		    public void MoveZeroes(int[] nums) {
		        int size = nums.Length;
		        int lastZeroIndex = 0;
		        for(int i = 0 ; i < size;++i){
		            if(nums[i] != 0){
		                Swap<int>(ref nums[i], ref nums[lastZeroIndex++]);
		            }
		        }
		    }
		}
		public static void Main()
		{
			int[] nums = new int[]{0,1,0,3,12};
			Solution sol = new Solution();
			sol.MoveZeroes(nums);
			foreach(int num in nums){
				Console.Write(" " + num);
			}
 
			Console.Read();
		}
	}
}