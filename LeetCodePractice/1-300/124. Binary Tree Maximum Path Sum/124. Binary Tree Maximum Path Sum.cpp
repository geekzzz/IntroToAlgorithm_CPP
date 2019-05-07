/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//遍历的函数的返回值为左分支与右分支的最大值加上当前节点后的值，然后每次遍历再判断一次左右分支和当前节点的和的值与记录的最大值的大小，注意左右分支如果小于0的话就设置为0，表示分支不算在path中
class Solution {
public:
	int maxv = INT_MIN;
	int maxPathSum(TreeNode* root) {
		helper(root);
		return maxv;
	}
	int helper(TreeNode* root)
	{
		if (!root)
			return 0;
		int l = max(0, helper(root->left));
		int r = max(0, helper(root->right));
		maxv = max(maxv, l + r + root->val);
		return max(l, r) + root->val;
	}
};