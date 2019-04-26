/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

//用 递归的方式
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res;
		if (!n)
			return res;
		return gen(1, n);
	}
	vector<TreeNode*> gen(int start, int end)
	{
		vector<TreeNode*> res;
		if (start > end)
		{
			res.push_back(NULL);
			return res;
		}
		if (start == end)
		{
			TreeNode* root = new TreeNode(start);
			res.push_back(root);
			return res;
		}
		for (int i = start; i <= end; ++i)//注意这个for里的内容
		{
			vector<TreeNode*> left = gen(start, i - 1);
			vector<TreeNode*> right = gen(i + 1, end);
			for (auto x1 : left)
			{
				for (auto x2 : right)
				{
					TreeNode * root = new TreeNode(i);
					root->left = x1;
					root->right = x2;
					res.push_back(root);
				}
			}
		}
		return res;
	}
};