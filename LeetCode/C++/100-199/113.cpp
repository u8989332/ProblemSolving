class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> result;
        if(root == NULL){
            return result;
        }
        
        vector<int> curNodes;
        pathSum(root, sum, 0, curNodes, result);
        return result;
    }
private:
    void pathSum(TreeNode* curNode, int targetSum, int sum, vector<int>& curNodes, vector<vector<int>>& result){
        sum += curNode->val;
        curNodes.push_back(curNode->val);
        if(curNode->left == NULL && curNode->right == NULL && sum == targetSum){
            result.push_back(curNodes);
            return;
        }
        
        if(curNode->left != NULL){
            pathSum(curNode->left, targetSum, sum, curNodes, result);
            curNodes.pop_back();
        }
        
        if(curNode->right != NULL){
            pathSum(curNode->right, targetSum, sum, curNodes, result);
            curNodes.pop_back();
        }
    }
};
