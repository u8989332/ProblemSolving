using System;
using System.Collections.Generic;

namespace LeetCode224
{
    public class Solution {
        Stack<int> nums = new Stack<int>();
        Stack<char> oprs = new Stack<char>();
        private void Calculate(Stack<int> nums, Stack<char> oprs)
        {
            if(nums.Count < 2)
                return;
            
            int n1 = nums.Peek();
            nums.Pop();
            int n2 = nums.Peek();
            nums.Pop();
            char opr = oprs.Peek();
            oprs.Pop();
            if(opr == '+')
                nums.Push(n1 + n2);
            else if(opr == '-')
                nums.Push(n2 - n1);
        }
        
        public int Calculate(string s) {
            int len = s.Length;
            const int BEGIN_STATE = 0;
            const int NUBMER_STATE = 1;
            const int OPERATOR_STATE = 2;
            int currentState = BEGIN_STATE;
            int number = 0;
            int computeMode = 0;
            nums.Clear();
            oprs.Clear();
            for(int i = 0 ; i < len;++i)
            {
                if(s[i] == ' ')
                    continue;
                
                switch(currentState)
                {
                    case BEGIN_STATE:
                        if(Char.IsDigit(s[i]))
                        {
                            currentState = NUBMER_STATE;
                        }
                        else
                        {
                            currentState = OPERATOR_STATE;
                        }
                        i--;
                        break;
                    case NUBMER_STATE:
                        if(Char.IsDigit(s[i]))
                        {
                            number = number * 10 + (s[i] - '0');
                        }
                        else
                        {
                            currentState = OPERATOR_STATE;
                            nums.Push(number);
                            if(computeMode == 1)
                            {
                                Calculate(nums, oprs);
                                computeMode = 0;
                            }
                            number = 0;
                            i--;
                        }
                        break;
                    case OPERATOR_STATE:
                        if(Char.IsDigit(s[i]))
                        {
                            currentState = NUBMER_STATE;
                            i--;
                        }
                        else if(s[i] == '(')
                        {
                            currentState = NUBMER_STATE;
                            computeMode = 0;
                        }
                        else if(s[i] == ')')
                        {
                            Calculate(nums, oprs);
                        }
                        else if(s[i] == '+' || s[i] == '-')
                        {
                            oprs.Push(s[i]);
                            computeMode = 1;
                        }
                        break;
                }
            }
            
            if(number != 0)
            {
                nums.Push(number);
                Calculate(nums, oprs);
            }
            
            if(number == 0 && nums.Count == 0)
            {
                return 0;
            }
            
            return nums.Peek();
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Solution s = new Solution();

            Console.WriteLine(s.Calculate("1 + 5 - 3"));
            Console.WriteLine(s.Calculate("(1+(4+5+2)-3)+(6+8)"));
            Console.WriteLine(s.Calculate("(500)"));
        }
    }
}
