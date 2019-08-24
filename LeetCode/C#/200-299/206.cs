using System;

namespace LeetCode206
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
        public ListNode ReverseList(ListNode head) {
            ListNode newHead = null;
            while(head!=null)
            {
                ListNode next = head.next;
                head.next = newHead;
                newHead = head;
                head = next;
            }
            return newHead;
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
            ListNode newHead = sol.ReverseList(node1);
            TraverseNode(newHead);
        }
    }
}
