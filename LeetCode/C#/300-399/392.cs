using System;

namespace LeetCode392
{
    public class Solution
    {
        public bool IsSubsequence(string s, string t)
        {
            bool isSub = false;
            int i, j;
            for (i = 0, j = 0; i < s.Length && j < t.Length;)
            {
                if (s[i] == t[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    j++;
                }
            }

            if (i >= s.Length)
            {
                isSub = true;
            }

            return isSub;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine(new Solution().IsSubsequence("abc", "ahbgdc"));
            Console.Read();
        }
    }
}
