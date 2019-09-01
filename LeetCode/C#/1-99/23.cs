using System;

namespace LeetCode23
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
        public ListNode MergeKLists(ListNode[] lists) {
            if(lists.Length == 0){
                return null;
            }
            
            return mergeHelper(lists, 0, lists.Length - 1);
        }
        
        ListNode mergeHelper(ListNode[] lists, int L, int R){
            if(L < R){
                int mid = (L + R) / 2;
                ListNode temp = MergeTwoLists(mergeHelper(lists, L, mid), mergeHelper(lists, mid + 1, R));
                return temp;
            }
            
            return lists[L];
        }
        
        ListNode MergeTwoLists(ListNode l1, ListNode l2) {
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
            ListNode nodeL1_2 = new ListNode(4);
            ListNode nodeL1_3 = new ListNode(5);

            ListNode nodeL2_1 = new ListNode(1);
            ListNode nodeL2_2 = new ListNode(3);
            ListNode nodeL2_3 = new ListNode(4);

            ListNode nodeL3_1 = new ListNode(2);
            ListNode nodeL3_2 = new ListNode(6);

            nodeL1_1.next = nodeL1_2;
            nodeL1_2.next = nodeL1_3;

            nodeL2_1.next = nodeL2_2;
            nodeL2_2.next = nodeL2_3;

            nodeL3_1.next = nodeL3_2;

            ListNode[] lists = new ListNode[3];
            lists[0] = nodeL1_1;
            lists[1] = nodeL2_1;
            lists[2] = nodeL3_1;

            Solution sol = new Solution();
            ListNode newHead = sol.MergeKLists(lists);
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
