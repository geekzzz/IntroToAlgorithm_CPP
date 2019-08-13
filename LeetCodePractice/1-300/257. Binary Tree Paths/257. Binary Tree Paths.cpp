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
	vector<string> res;
	vector<string> binaryTreePaths(TreeNode* root) {
		if (!root)
			return res;
		string path(to_string(root->val));
		if (root->left)
			dfs(root->left, path);
		if (root->right)
			dfs(root->right, path);
		if (!root->left && !root->right)
			res.push_back(path);
		return res;
	}
	void dfs(TreeNode * root, string path)
	{
		path += "->" + to_string(root->val);
		if (!root->left && !root->right)
		{
			res.push_back(path);
			return;
		}
		if (root->left)
			dfs(root->left, path);
		if (root->right)
			dfs(root->right, path);

	}
};