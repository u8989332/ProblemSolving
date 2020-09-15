using System;
using System.Collections.Generic;

namespace LeetCode739
{
    public class Solution {
        public int[] DailyTemperatures(int[] T) {
            Stack<int> st = new Stack<int>();
            int size = T.Length;

            int[] ans = new int[size];

            for(int i = 0 ; i < size;++i){
                while(st.Count > 0){
                    if(T[i] > T[st.Peek()]){
                        ans[st.Peek()] = i - st.Peek();
                        st.Pop();
                    }
                    else{
                        break;
                    }
                }

                st.Push(i);
            }
        
            return ans;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int[] t = new int[] {73, 74, 75, 71, 69, 72, 76, 73};
            int[] ans = new Solution().DailyTemperatures(t);
            
            foreach (int item in ans)
            {
                Console.WriteLine(item);
            }

            Console.ReadLine();
        }
    }
}
