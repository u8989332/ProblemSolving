using System;
using System.Collections.Generic;
namespace LeetCode138
{

    /*
    // Definition for a Node.
    */
    public class Node {
        public int val;
        public Node next;
        public Node random;

        public Node(){}
        public Node(int _val,Node _next,Node _random) {
            val = _val;
            next = _next;
            random = _random;
        }
    }

    public class Solution {
        public Node CopyRandomList(Node head) {
            Dictionary<Node, Node> nodeMap = new Dictionary<Node, Node>();
            if(head == null)
                return null;
            
            Node temp = head;
            while(temp != null) {
                nodeMap[temp] = new Node(temp.val, null, null);
                temp = temp.next;
            }
            
            temp = head;
            while(temp != null) {
                nodeMap[temp].next = temp.next == null ?  null : nodeMap[temp.next];
                nodeMap[temp].random = temp.random == null ? null : nodeMap[temp.random];
                temp=temp.next;
            }
            
            return nodeMap[head];
        }
    }
    class Program
    {
        
        static void Main(string[] args)
        {
            Node node1 = new Node(1, null, null);
            Node node2 = new Node(2, null, null);
            Node node3 = new Node(3, null, null);

            node1.next = node2;
            node2.next = node3;

            node1.random = node3;
            node2.random = node1;
            node3.random = node2;

            Solution sol = new Solution();
            TraverseNode(node1);
            Console.WriteLine("===========");
            Node newDeepCopyHead = sol.CopyRandomList(node1);
            TraverseNode(newDeepCopyHead);
        }

        static void TraverseNode(Node head)
        {
            Console.WriteLine("Start traversal");
            while(head != null)
            {
                Console.WriteLine("Current value : " + head.val);
                if(head.next != null)
                    Console.WriteLine("Next value : "  + head.next.val);
                else
                    Console.WriteLine("Next is null");

                if(head.random != null)
                    Console.WriteLine("Random value : " + head.random.val);
                else
                    Console.WriteLine("Random is null");

                head = head.next;
            }
            Console.WriteLine("Finish traversal");
        }
    }
}
