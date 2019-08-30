using System;

namespace LeetCode86
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
    public ListNode Partition(ListNode head, int x) {
        ListNode lessNode = new ListNode(0);
        ListNode greaterNode = new ListNode(0);
        ListNode lessPtr = lessNode;
        ListNode greaterPtr = greaterNode;
        while(head != null)
        {
            if(head.val < x) {
                lessPtr.next = head;
                lessPtr = lessPtr.next;
            }
            else {
                greaterPtr.next = head;
                greaterPtr = greaterPtr.next;
            }
            head = head.next;
        }
        lessPtr.next = greaterNode.next;
        greaterPtr.next = null;
        
        return lessNode.next;
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
            ListNode node2 = new ListNode(4);
            ListNode node3 = new ListNode(3);
            ListNode node4 = new ListNode(2);
            ListNode node5 = new ListNode(5);
            ListNode node6 = new ListNode(2);

            node1.next = node2;
            node2.next = node3;
            node3.next = node4;
            node4.next = node5;
            node5.next = node6;
            node6.next = null;

            Solution sol = new Solution();
            ListNode newListHead = sol.Partition(node1, 3);
            TraverseNode(newListHead);
        }
    }
}
