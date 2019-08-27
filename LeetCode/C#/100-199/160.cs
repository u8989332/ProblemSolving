using System;

namespace LeetCode160
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
        public ListNode GetIntersectionNode(ListNode headA, ListNode headB) {
            int lenA = getLen(headA);
            int lenB = getLen(headB);
            if(lenA > lenB)
            {
                int diff = lenA - lenB;
                headA = move(headA, diff);
            }
            else if(lenA < lenB)
            {
                int diff = lenB - lenA;
                headB = move(headB, diff);
            }
            
            while(headA != null && headB != null)
            {
                if(headA == headB)
                    return headA;
                
                headA = headA.next;
                headB = headB.next;
            }
            return null;
        }
        
        private int getLen(ListNode head) {
            ListNode temp = head;
            int counts = 0;
            while(temp != null)
            {
                counts++;
                temp = temp.next;
            }
            
            return counts;
        }
        
        private ListNode move(ListNode node, int moveCount) {
            while(moveCount-- > 0 && node != null)
            {
                node = node.next;
            }
            return node;
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            ListNode nodeA1 = new ListNode(4);
            ListNode nodeA2 = new ListNode(1);
            ListNode nodeC1 = new ListNode(8);
            ListNode nodeC2 = new ListNode(4);
            ListNode nodeC3 = new ListNode(5);
            ListNode headA = nodeA1;

            nodeA1.next = nodeA2;
            nodeA2.next = nodeC1;
            nodeC1.next = nodeC2;
            nodeC2.next = nodeC3;
            nodeC3.next = null;

            ListNode nodeB1 = new ListNode(5);
            ListNode nodeB2 = new ListNode(0);
            ListNode nodeB3 = new ListNode(1);
            ListNode headB = nodeB1;
            nodeB1.next = nodeB2;
            nodeB2.next = nodeB3;
            nodeB3.next = nodeC1;

            Solution sol = new Solution();
            ListNode intersectVal = sol.GetIntersectionNode(headA, headB);
            if(intersectVal != null)
                Console.WriteLine("intersectVal = " + intersectVal.val);
            else
                Console.WriteLine("No intersectVal");
        }
    }
}
