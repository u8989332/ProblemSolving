using System;

namespace LeetCode21
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
        public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
            ListNode tempHead = new ListNode(0);
            ListNode temp = tempHead;
            
            while(l1 != null && l2 != null)
            {
                if(l1.val < l2.val)
                {
                    temp.next = l1;
                    l1 = l1.next;
                }
                else
                {
                    temp.next = l2;
                    l2 = l2.next;
                }
                temp = temp.next;
            }
            
            if(l1 != null)
                temp.next = l1;
            
            if(l2 != null)
                temp.next = l2;
            
            return tempHead.next;
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            ListNode nodeL1_1 = new ListNode(1);
            ListNode nodeL1_2 = new ListNode(2);
            ListNode nodeL1_3 = new ListNode(4);
            ListNode nodeL1_4 = new ListNode(7);

            ListNode nodeL2_1 = new ListNode(1);
            ListNode nodeL2_2 = new ListNode(3);
            ListNode nodeL2_3 = new ListNode(5);

            nodeL1_1.next = nodeL1_2;
            nodeL1_2.next = nodeL1_3;
            nodeL1_3.next = nodeL1_4;

            nodeL2_1.next = nodeL2_2;
            nodeL2_2.next = nodeL2_3;

            Solution sol = new Solution();
            ListNode newHead = sol.MergeTwoLists(nodeL1_1, nodeL2_1);
            TraverseNode(newHead);
        }

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
    }
}
