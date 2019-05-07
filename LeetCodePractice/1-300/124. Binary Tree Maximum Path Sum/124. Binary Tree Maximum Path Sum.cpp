/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
//�����ĺ����ķ���ֵΪ���֧���ҷ�֧�����ֵ���ϵ�ǰ�ڵ���ֵ��Ȼ��ÿ�α������ж�һ�����ҷ�֧�͵�ǰ�ڵ�ĺ͵�ֵ���¼�����ֵ�Ĵ�С��ע�����ҷ�֧���С��0�Ļ�������Ϊ0����ʾ��֧������path��
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