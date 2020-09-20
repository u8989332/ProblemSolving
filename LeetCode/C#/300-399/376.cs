using System;

namespace LeetCode376
{
    public class Solution {
        const int BEGIN = 0;
        const int UP = 1;
        const int DOWN = 2;
        public int WiggleMaxLength(int[] nums) {
            if(nums.Length < 2){
                return nums.Length;
            }
            
            int curState = BEGIN;
            int maxLength = 1;
            for(int i = 1;i < nums.Length ; ++i){
                switch(curState){
                    case BEGIN:
                        if(nums[i-1] > nums[i]){
                            curState = DOWN;
                            maxLength++;
                        }
                        else if(nums[i-1] < nums[i]){
                            curState = UP;
                            maxLength++;
                        }
                        break;
                    case UP:
                        if(nums[i-1] > nums[i]){
                            curState = DOWN;
                            maxLength++;
                        }
                        break;
                    case DOWN:
                        if(nums[i-1] < nums[i]){
                            curState = UP;
                            maxLength++;
                        }
                        break;
                }
            }
            
            return maxLength;
            
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int[] nums = new int[]{1,17,5,10,13,15,10,5,16,8};
            Console.WriteLine(new Solution().WiggleMaxLength(nums));
            Console.Read();
        }
    }
}
