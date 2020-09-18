#include <iostream>
#include <string>
#include <sstream>
#include <map>
using namespace std;

map<int, int> inorderMapIndex;
int postorderNodes[10005];
int inorderNodes[10005];
int ans;
int ans_sums;

struct TreeNode{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode(){};

	TreeNode(int initVal)
	{
		val = initVal;
		left = NULL;
		right = NULL;
	}
};

TreeNode* parseNodes(int L1, int R1, int L2, int R2){
	if(L1 > R1){
		return NULL;
	}
	
	int inorderIndex = inorderMapIndex[postorderNodes[R2]];
	int leftCounts = inorderIndex - L1;
	TreeNode* curParent = new TreeNode(postorderNodes[R2]);
	curParent->left = parseNodes(L1, inorderIndex-1, L2, L2 + leftCounts - 1);
	curParent->right = parseNodes(inorderIndex + 1, R1, L2 + leftCounts, R2 - 1);
	
	return curParent;
}

void findLeastVal(TreeNode* node, int sum){
	if(node == NULL)
		return;
	
	sum += node->val;
	
	findLeastVal(node->left, sum);
	findLeastVal(node->right, sum);
	
	if(node->left == NULL && node->right == NULL){
		if(sum < ans_sums || (sum == ans_sums && ans > node->val)){
			ans = node->val;
			ans_sums = sum;
		}
	}
	

}


int main() 
{
    string s;
	while(getline(cin, s)){
		inorderMapIndex.clear();
		int curVal;
		int totalLength = 0;
		
		stringstream ss1(s);
		while(ss1 >> curVal){
			inorderMapIndex[curVal] = totalLength;
			inorderNodes[totalLength] = curVal;
			totalLength++;
		}
		
		totalLength = 0;
		getline(cin, s);
		stringstream ss2(s);
		while(ss2 >> curVal){
			postorderNodes[totalLength] = curVal;
			totalLength++;
		}
		
		TreeNode* root = parseNodes(0, totalLength-1, 0, totalLength-1);
		
		ans_sums = 999999999;
		findLeastVal(root, 0);
		
		cout << ans << endl;
	}


    return 0;
}