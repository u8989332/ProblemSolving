using System;
using System.Collections.Generic;

namespace LeetCode155
{
    public class MinStack {

        Stack<int> myStack = new Stack<int>();
        Stack<int> minStack = new Stack<int>();
        
        /** initialize your data structure here. */
        public MinStack() {
            
        }
        
        public void Push(int x) {
            myStack.Push(x);
            if(minStack.Count == 0 || minStack.Peek() >= x) {
                minStack.Push(x);
            }
            
        }
        
        public void Pop() {
            int curVal = myStack.Peek();
            if(curVal == minStack.Peek())
                minStack.Pop();
            
            myStack.Pop();
            
        }
        
        public int Top() {
            return myStack.Peek();
            
        }
        
        public int GetMin() {
            return minStack.Peek();
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            MinStack myStack = new MinStack();
            myStack.Push(1);
            myStack.Push(2);
            myStack.Push(-1);
            myStack.Push(-1);
            Console.WriteLine(myStack.GetMin());
            Console.WriteLine(myStack.Top());
            myStack.Push(3);
            myStack.Pop();
            myStack.Pop();
            Console.WriteLine(myStack.GetMin());
            Console.WriteLine(myStack.Top());
        }
    }
}
