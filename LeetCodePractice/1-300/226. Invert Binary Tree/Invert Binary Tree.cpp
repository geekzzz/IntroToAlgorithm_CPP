/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//�����õݹ�ķ�ʽҲ������ջ�ķ�ʽ
class Solution {
public:
	TreeNode* invertTree(TreeNode* root) {
		stack<TreeNode*> s;
		s.push(root);
		while (!s.empty())
		{
			TreeNode* t = s.top();
			s.pop();

			if (t)
			{
				s.push(t->left);
				s.push(t->right);
				swap(t->left, t->right);
			}

		}
		return root;
	}
};