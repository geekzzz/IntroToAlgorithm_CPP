/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//�Ż������ⷨ�������ԼӸ�bool found������ҵ��˺���ľͽ�����
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