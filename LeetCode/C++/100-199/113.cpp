#include <iostream>
#include <vector>
using namespace std;

// Definition for a Node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

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

int main()
{
	TreeNode node7(7, NULL, NULL);
	TreeNode node8(2, NULL, NULL);
	TreeNode node4(11, &node7, &node8);
	
	TreeNode node2(4, &node4, NULL);
	
	TreeNode node9(5, NULL, NULL);
	TreeNode node10(1, NULL, NULL);
	
	TreeNode node6(4, &node9, &node10);

	TreeNode node5(13, NULL, NULL);
	
    TreeNode node3(8, &node5, &node6);
    TreeNode node1(5, &node2, &node3);
    
    Solution sol;
    vector<vector<int>> result = sol.pathSum(&node1, 22);
	for(int i = 0 ; i < result.size();++i){
		for(int j = 0;j < result[i].size();++j){
			cout << " " << result[i][j];
		}
		cout << endl;
	}

    return 0;
}
