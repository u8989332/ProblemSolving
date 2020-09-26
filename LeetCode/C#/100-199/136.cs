using System;

namespace LeetCode136
{
    public class Solution
    {
        public int SingleNumber(int[] nums)
        {
            int ans = 0;
            foreach (int num in nums)
            {
                ans ^= num;
            }

            return ans;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int[] nums = new int[5]{1,2,4,4,2};
            Console.WriteLine(new Solution().SingleNumber(nums));
            Console.Read();
        }
    }
}
