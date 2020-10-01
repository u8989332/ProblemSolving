using System;

namespace LeetCode26
{
    public class Solution {
	    public int RemoveDuplicates(int[] nums) {
	        int count = 0 ;
	        int originSize = nums.Length;
	        for(int i = 1 ; i < originSize;++i){
	            if(nums[i] == nums[i-1]){
	                count++;
	            }
	            nums[i-count] = nums[i];
	        }
 
	        return originSize - count;
	    }
	}
    class Program
    {
        static void Main(string[] args)
        {
            Solution sol = new Solution();
            int[] nums = new int[]{1,1,2};
            int len = sol.RemoveDuplicates(nums);
            for(int i = 0 ;i < len;++i){
                Console.Write(" " + nums[i]);
            }
            Console.Read();
        }
    }
}
