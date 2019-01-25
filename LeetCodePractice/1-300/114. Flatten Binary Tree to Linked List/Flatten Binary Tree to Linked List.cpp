/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//��һ����ô��
class Solution {
public:
	TreeNode * p = nullptr;
	void flatten(TreeNode* root) {
		if (!root)
			return;
		flatten(root->right);
		flatten(root->left);
		root->right = p;
		root->left = nullptr;
		p = root;
	}
};