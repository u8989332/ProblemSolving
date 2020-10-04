using System;
using System.Collections.Generic;

namespace LeetCode217
{
    public class Solution {
		public bool ContainsDuplicate(int[] nums) {
			HashSet<int> repeat = new HashSet<int>();
			for(int i = 0; i < nums.Length;++i){
				if(repeat.Contains(nums[i])){
					return true;
				}
				
				repeat.Add(nums[i]);
			}
			
			return false;
		}
	}

    class Program
    {
        static void Main(string[] args)
        {
            int[] nums = new int[]{1,2,3,1};
            Solution sol = new Solution();
            Console.WriteLine(sol.ContainsDuplicate(nums));
            Console.Read();
        }
    }
}
