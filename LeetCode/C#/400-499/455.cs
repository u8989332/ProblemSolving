using System;

namespace LeetCode455
{
    public class Solution {
        public int FindContentChildren(int[] g, int[] s) {
            Array.Sort(g); 
            Array.Sort(s);
            int child = 0;
            int cookie = 0;
            while(child < g.Length && cookie < s.Length){
                if(g[child] <= s[cookie]){
                    child++;
                }
                cookie++;
            }
            
            return child;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            int[] g = new int[] {1, 2};
            int[] s = new int[] {1, 2, 3};
            Console.WriteLine(new Solution().FindContentChildren(g, s));
            Console.Read();
        }
    }
}
