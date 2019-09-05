using System;
using System.Collections.Generic;
namespace LeetCode232
{
    public class MyQueue {
        Stack<int> myStack = new Stack<int>();
        Stack<int> bufferStack = new Stack<int>();

        /** Initialize your data structure here. */
        public MyQueue() {
            
        }
        
        /** Push element x to the back of queue. */
        public void Push(int x) {
            myStack.Push(x);
        }
        
        /** Removes the element from in front of queue and returns that element. */
        public int Pop() {
            if(bufferStack.Count == 0) {
                TransferToBuffer();
            }

            int top = bufferStack.Peek();
            bufferStack.Pop();
            return top;
        }
        
        /** Get the front element. */
        public int Peek() {
            if(bufferStack.Count == 0) {
                TransferToBuffer();
            }
            
            return bufferStack.Peek();
        }
        
        /** Returns whether the queue is empty. */
        public bool Empty() {
            return myStack.Count == 0 && bufferStack.Count == 0;
        }
        
        private void TransferToBuffer() {
            while(myStack.Count != 0)
            {
                bufferStack.Push(myStack.Peek());
                myStack.Pop();
            }
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            MyQueue myQueue = new MyQueue();
            myQueue.Push(1);
            myQueue.Push(2);
            myQueue.Push(3);
            Console.WriteLine(myQueue.Peek());
            Console.WriteLine(myQueue.Pop());
            Console.WriteLine(myQueue.Peek());
            Console.WriteLine(myQueue.Empty());
            myQueue.Pop();
            myQueue.Pop();
            Console.WriteLine(myQueue.Empty());
        }
    }
}
