using System;
using System.Collections.Generic;

namespace LeetCode113
{
    public class TreeNode
    {
        public int val;
        public TreeNode left;
        public TreeNode right;
        public TreeNode(int val = 0, TreeNode left = null, TreeNode right = null)
        {
            this.val = val;
            this.left = left;
            this.right = right;
        }
    }

    public class Solution
    {
        public IList<IList<int>> PathSum(TreeNode root, int sum)
        {
            IList<IList<int>> result = new List<IList<int>>();
            if (root == null)
            {
                return result;
            }

            IList<int> curNodes = new List<int>();
            PathSum(root, sum, 0, curNodes, result);
            return result;
        }

        private void PathSum(TreeNode curNode, int targetSum, int sum, IList<int> curNodes, IList<IList<int>> result)
        {
            sum += curNode.val;
            curNodes.Add(curNode.val);
            if (curNode.left == null && curNode.right == null && sum == targetSum)
            {
                var copyList = new List<int>();
                copyList.AddRange(curNodes);
                result.Add(copyList);
                return;
            }

            if (curNode.left != null)
            {
                PathSum(curNode.left, targetSum, sum, curNodes, result);
                curNodes.RemoveAt(curNodes.Count - 1);
            }

            if (curNode.right != null)
            {
                PathSum(curNode.right, targetSum, sum, curNodes, result);
                curNodes.RemoveAt(curNodes.Count - 1);
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            TreeNode node7 = new TreeNode(7, null, null);
            TreeNode node8 = new TreeNode(2, null, null);
            TreeNode node4 = new TreeNode(11, node7, node8);
            
            TreeNode node2 = new TreeNode(4, node4, null);
            
            TreeNode node9 = new TreeNode(5, null, null);
            TreeNode node10 = new TreeNode(1, null, null);
            
            TreeNode node6 = new TreeNode(4, node9, node10);

            TreeNode node5 = new TreeNode(13, null, null);
            
            TreeNode node3 = new TreeNode(8, node5, node6);
            TreeNode node1 = new TreeNode(5, node2, node3);
            
            Solution sol = new Solution();
            IList<IList<int>> result = sol.PathSum(node1, 22);
            for(int i = 0 ; i < result.Count;++i){
                for(int j = 0;j < result[i].Count;++j){
                    Console.Write(" " + result[i][j]);
                }
                Console.WriteLine();
            }
            Console.ReadKey();
        }
    }
}
