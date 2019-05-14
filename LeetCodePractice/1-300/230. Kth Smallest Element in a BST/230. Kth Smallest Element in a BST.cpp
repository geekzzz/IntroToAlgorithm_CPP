/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//优化的最快解法，还可以加个bool found，如果找到了后面的就结束掉
class Solution {
public:
	int times = 0;
	int res = INT_MIN;
	int kthSmallest(TreeNode* root, int k) {
		helper(root, k);
		return res;
	}
	void helper(TreeNode* root, int k)
	{
		if (!root)
			return;
		helper(root->left, k);
		times++;
		if (times == k)
			res = root->val;
		helper(root->right, k);
	}
};