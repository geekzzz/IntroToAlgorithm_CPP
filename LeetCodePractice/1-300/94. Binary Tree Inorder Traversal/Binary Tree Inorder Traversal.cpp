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
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> result;
		t(result, root);
		return result;
	}
	void t(vector<int> &result, TreeNode* root)
	{
		if (root)
		{
			t(result, root->left);
			result.push_back(root->val);
			t(result, root->right);
		}
	}
};