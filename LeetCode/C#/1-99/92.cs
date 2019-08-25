using System;

namespace LeetCode92
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
        public ListNode ReverseBetween(ListNode head, int m, int n) {
            int changeLen = n - m + 1;
            ListNode preHead = null;
            ListNode result = head;
            while(head != null && (--m) > 0)
            {
                preHead = head;
                head = head.next;
            }
            ListNode newPreTail = head;
            ListNode newHead = null;
            while(head != null && changeLen > 0)
            {
                ListNode next = head.next;
                head.next = newHead;
                newHead = head;
                head = next;
                changeLen--;
            }
            
            newPreTail.next = head;
            if(preHead != null)
                preHead.next = newHead;
            else
                result = newHead;
            
            return result;
        }
    }

    class Program
    {
        static void TraverseNode(ListNode head)
        {
            Console.WriteLine("Start traversal");
            while(head != null)
            {
                Console.WriteLine(head.val);
                head = head.next;
            }
            Console.WriteLine("Finish traversal");
        }

        static void Main(string[] args)
        {
            ListNode node1 = new ListNode(1);
            ListNode node2 = new ListNode(2);
            ListNode node3 = new ListNode(3);
            ListNode node4 = new ListNode(4);
            ListNode node5 = new ListNode(5);
            node1.next = node2;
            node2.next = node3;
            node3.next = node4;
            node4.next = node5;
            node5.next = null;
            TraverseNode(node1);

            Solution sol = new Solution();
            ListNode newHead = sol.ReverseBetween(node1, 2, 4);
            TraverseNode(newHead);
        }
    }
}
