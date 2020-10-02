using System;

namespace LeetCode122
{
    public class Solution {
		public int MaxProfit(int[] prices) {
			int maxAns = 0;
			for(int i = 1 ; i < prices.Length;++i){
				if(prices[i] > prices[i-1]){
					maxAns += prices[i] - prices[i-1];
				}
			}
			
			return maxAns;
		}
	}
	
    public class Program
    {
        public static void Main(string[] args)
        {
            int[] prices = new int[]{7,1,5,3,6,4};
            Console.WriteLine(new Solution().MaxProfit(prices));
            Console.Read();
        }
    }
}
