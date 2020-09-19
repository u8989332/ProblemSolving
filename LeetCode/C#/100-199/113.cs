public class Solution {
    public IList<IList<int>> PathSum(TreeNode root, int sum) {
        IList<IList<int>> result = new List<IList<int>>();
        if(root == null){
            return result;
        }
        
        IList<int> curNodes = new List<int>();
        PathSum(root, sum, 0, curNodes, result);
        return result;
    }
    
    private void PathSum(TreeNode curNode, int targetSum, int sum, IList<int> curNodes, IList<IList<int>> result){
        sum += curNode.val;
        curNodes.Add(curNode.val);
        if(curNode.left == null && curNode.right == null && sum == targetSum){
            var copyList = new List<int>();
            copyList.AddRange(curNodes);
            result.Add(copyList);
            return;
        }
        
        if(curNode.left != null){
            PathSum(curNode.left, targetSum, sum, curNodes, result);
            curNodes.RemoveAt(curNodes.Count - 1);
        }
        
        if(curNode.right != null){
            PathSum(curNode.right, targetSum, sum, curNodes, result);
            curNodes.RemoveAt(curNodes.Count - 1);
        }
    }
}