using System;

namespace LeetCode189
{
	public class Solution {
	    public void Rotate(int[] nums, int k) {
	        int n = nums.Length;
	        if((k % n)== 0){
	            return;
	        }
	        
	        k = k % n;
	        int temp1, temp2;
	        int counts = 0;
	        for(int start = 0 ; counts < n;++start){
	            int current = start;
	            temp1 = nums[start];
	            do{
	                int next = (current + k) % n;
	                temp2 = nums[next];
	                nums[next] = temp1;
	                temp1 = temp2;
	                current = next;
	                counts++;
	            }while(current!= start);
	        }
	    }
	}
	public class Program
	{
		public static void Main()
		{
			int[] nums = new int[]{1,2,3,4,5,6,7};
			Solution sol = new Solution();
			sol.Rotate(nums, 3);
			for(int i = 0;i < nums.Length;++i){
				Console.Write(" " + nums[i]);
			}
		}
	}
}
