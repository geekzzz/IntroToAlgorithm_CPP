/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/

/*
可以发现的规律是：
1. 先序遍历的从左数第一个为整棵树的根节点。
2. 中序遍历中根节点是左子树右子树的分割点。

再看这个树的左子树：
先序遍历为: 2 4 5
中序遍历为: 4 2 5
依然可以套用上面发现的规律。

右子树：
先序遍历为: 3 6 7
中序遍历为: 6 3 7
也是可以套用上面的规律的。

所以这道题可以用递归的方法解决。
具体解决方法是：
通过先序遍历找到第一个点作为根节点，在中序遍历中找到根节点并记录index。
因为中序遍历中根节点左边为左子树，所以可以记录左子树的长度并在先序遍历中依据这个长度找到左子树的区间，用同样方法可以找到右子树的区间。
递归的建立好左子树和右子树就好。
*/

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		TreeNode* root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
		return root;
	}
	TreeNode* build(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend)
	{
		if (prestart > preend || instart > inend)//结束条件
			return nullptr;
		TreeNode* root = new TreeNode(preorder[prestart]);//该节点的值就是preorder[prestart]
		int inindex;
		for (int i = instart; i <= inend; ++i)
		{
			if (inorder[i] == preorder[prestart])//找到中序中，先序的根节点的位置
				inindex = i;
		}
		int len = inindex - instart;//计算划分的前半部分数组的长度（被分为两部分）
		root->left = build(preorder, prestart + 1, prestart + len, inorder, instart, inindex - 1);//prestart为当前节点的值，所以舍去prestart，pre数组从prestart + 1 开始， prestart + len结束。in数组从instart开始, inindex - 1结束
		root->right = build(preorder, prestart + len + 1, preend, inorder, inindex + 1, inend);//因为prestart在pre数组最前面，而左右两个子树数组在后面是相邻的，所以这里的pre数组从prestart + len + 1开始，到preend结束。in数组inindex + 1开始, inend结束
		return root;
	}
};