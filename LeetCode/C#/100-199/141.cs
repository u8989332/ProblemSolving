using System;

namespace LeetCode141
{
     /**
    * Definition for singly-linked list.
    */
    public class ListNode {
        public int val;
        public ListNode next;
        public ListNode(int x) { val = x; }
    }

    public class Solution {
        public bool HasCycle(ListNode head) {
            ListNode slow = head;
            ListNode fast = head;
            
            while(fast != null && fast.next != null)
            {
                slow = slow.next;
                fast = fast.next.next;
                if(slow == fast)
                    return true;
            }
            
            return false;
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            ListNode node1 = new ListNode(3);
            ListNode node2 = new ListNode(2);
            ListNode node3 = new ListNode(0);
            ListNode node4 = new ListNode(-4);

            node1.next = node2;
            node2.next = node3;
            node3.next = node4;
            node4.next = node2;

            Solution sol = new Solution();
            Console.WriteLine("Result = " + sol.HasCycle(node1));
        }
    }
}
