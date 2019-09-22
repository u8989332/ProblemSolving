using System;

namespace LeetCode215
{
    public class Solution {
        private void Swap(int[] nums, int i, int j)
        {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        
        private int QuickSelect(int[] nums, int k, int left , int right)
        {
            int i = left;
            int j = right;
            int pivot = nums[left];
            int len = nums.Length;
            while(i <= j)
            {
                while(nums[i] > pivot)
                {
                    i++;
                }
                
                while(nums[j] < pivot)
                {
                    j--;
                }
                
                if(i <= j)
                {
                    Swap(nums, i, j);
                    i++;
                    j--;
                }
            }
            
            if(left < j && k <= j)
                return QuickSelect(nums, k, left, j);
            
            if(right > i && k >= i)
                return QuickSelect(nums, k, i, right);
            
            return nums[k];
        }
        
        public int FindKthLargest(int[] nums, int k) {
            return QuickSelect(nums, k - 1 , 0, nums.Length - 1);
        }
        
        
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();
            int[] nums = {4,1,6,5,9,2};
            Console.WriteLine(s.FindKthLargest(nums, 2));
        }
    }
}
