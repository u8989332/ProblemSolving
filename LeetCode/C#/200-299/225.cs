using System;
using System.Collections.Generic;
namespace LeetCode225
{
    public class MyStack {

        Queue<int> myQueue = new Queue<int>();
        /** Initialize your data structure here. */
        public MyStack() {
            
        }
        
        /** Push element x onto stack. */
        public void Push(int x) {
            myQueue.Enqueue(x);
            int size = myQueue.Count;
            for(int i = 0 ; i < size -1;++i)
            {
                myQueue.Enqueue(Pop());
            }
        }
        
        /** Removes the element on top of the stack and returns that element. */
        public int Pop() {
            return myQueue.Dequeue();
        }
        
        /** Get the top element. */
        public int Top() {
            return myQueue.Peek();
        }
        
        /** Returns whether the stack is empty. */
        public bool Empty() {
            return myQueue.Count == 0;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            MyStack myStack = new MyStack();
            myStack.Push(1);
            myStack.Push(2);
            myStack.Push(3);
            Console.WriteLine(myStack.Top());
            Console.WriteLine(myStack.Pop());
            Console.WriteLine(myStack.Top());
            Console.WriteLine(myStack.Empty());
            myStack.Pop();
            myStack.Pop();
            Console.WriteLine(myStack.Empty());
        }
    }
}
