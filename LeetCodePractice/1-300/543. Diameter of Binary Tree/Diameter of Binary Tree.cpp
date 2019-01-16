/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {
public:
	int maxd = 0;
	int diameterOfBinaryTree(TreeNode* root) {
		depth(root);
		return maxd;
	}
	int depth(TreeNode* root)
	{
		if (!root)
			return 0;
		int left = depth(root->left);
		int right = depth(root->right);
		maxd = max(maxd, left + right);
		return max(left, right) + 1;
	}
};