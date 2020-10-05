using System;
using System.Linq;
using System.Collections.Generic;

namespace LeetCode350
{
	public class Program
	{
		public class Solution {
		    public int[] Intersect(int[] nums1, int[] nums2) {
		        Array.Sort(nums1);
		        Array.Sort(nums2);
		        List<int> ans = new List<int>();
		        for(int i = 0, j = 0;i < nums1.Length && j < nums2.Length;){
		            if(nums1[i] == nums2[j]){
		                ans.Add(nums1[i]);
		                i++;
		                j++;
		            }
		            else if(nums1[i] > nums2[j]){
		                j++;
		            }
		            else{
		                i++;
		            }
		        }
		        
		        return ans.ToArray();
		    }
		}
		
		public static void Main()
		{
			Solution sol = new Solution();
			int[] nums1 = new int[]{1,2,2,1};
			int[] nums2 = new int[]{2,2};
			var ans = sol.Intersect(nums1, nums2);
			foreach(int num in ans){
				Console.Write(" " + num);
			}
			Console.Read();
		}
	}
}