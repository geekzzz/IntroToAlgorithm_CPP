#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <set>
#include <string>
using namespace std;


struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
void PrintTreePreOrder(TreeNode * root);
void PrintTreeInOrder(TreeNode * root);
void PrintTreePostOrder(TreeNode * root);
TreeNode* CreateBiTreePreAndInOrder(vector<int> pre, vector<int> in);
TreeNode* CreateBitreePreAndInOrderFunction(vector<int> pre, int preStart, int preEnd, vector<int> in, int inStart, int inEnd);

TreeNode* CreateBiTreePreAndInOrder(vector<int> pre, vector<int> in)//通过先序和中序建立二叉树
{
	if ((pre.size() != in.size()) || pre.size() == 0 || in.size() == 0)
		return NULL;
	return CreateBitreePreAndInOrderFunction(pre, 0, pre.size() - 1, in, 0, in.size() - 1);
}

TreeNode* CreateBitreePreAndInOrderFunction(vector<int> pre, int preStart, int preEnd, vector<int> in, int inStart, int inEnd)//由createBiTreePreAndInOrder(vector<int> pre,vector<int> in)调用
{
	if (preStart > preEnd || inStart > inEnd)
		return NULL;
	TreeNode* root = new TreeNode(pre[preStart]);
	for (int i = inStart; i <= inEnd; ++i)
	{
		if (in[i] == pre[preStart])
		{
			root->left = CreateBitreePreAndInOrderFunction(pre, preStart + 1, preStart + i - inStart, in, inStart, i - 1);
			root->right = CreateBitreePreAndInOrderFunction(pre, preStart + i - inStart + 1, preEnd, in, i + 1, inEnd);
		}
	}
	return root;
}

void PrintTreePreOrder(TreeNode * root)
{
	if (root != NULL)
	{
		cout << root->val << ",";
		PrintTreePreOrder(root->left);
		PrintTreePreOrder(root->right);
	}
}
void PrintTreeInOrder(TreeNode * root)
{

	if (root != NULL)
	{
		PrintTreeInOrder(root->left);
		cout << root->val << ",";
		PrintTreeInOrder(root->right);
	}

}
void PrintTreePostOrder(TreeNode * root)
{
	if (root != NULL)
	{
		PrintTreePostOrder(root->left);
		PrintTreePostOrder(root->right);
		cout << root->val << ",";
	}
}

int main()
{
	int a[] = { 1,2,4,7,3,5,6,8 };
	int b[] = { 4,7,2,1,5,3,8,6 };
	vector<int> pre(a, a + 8);
	vector<int> in(b, b + 8);
	TreeNode* root = CreateBiTreePreAndInOrder(pre, in);
	PrintTreePreOrder(root);
	cout << endl;
	PrintTreeInOrder(root);
	cout << endl;
	PrintTreePostOrder(root);
	system("pause");
}

