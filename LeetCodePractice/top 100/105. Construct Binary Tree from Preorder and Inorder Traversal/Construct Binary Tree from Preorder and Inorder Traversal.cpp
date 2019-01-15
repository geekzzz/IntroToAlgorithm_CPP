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
���Է��ֵĹ����ǣ�
1. ��������Ĵ�������һ��Ϊ�������ĸ��ڵ㡣
2. ��������и��ڵ����������������ķָ�㡣

�ٿ����������������
�������Ϊ: 2 4 5
�������Ϊ: 4 2 5
��Ȼ�����������淢�ֵĹ��ɡ�

��������
�������Ϊ: 3 6 7
�������Ϊ: 6 3 7
Ҳ�ǿ�����������Ĺ��ɵġ�

�������������õݹ�ķ��������
�����������ǣ�
ͨ����������ҵ���һ������Ϊ���ڵ㣬������������ҵ����ڵ㲢��¼index��
��Ϊ��������и��ڵ����Ϊ�����������Կ��Լ�¼�������ĳ��Ȳ������������������������ҵ������������䣬��ͬ�����������ҵ������������䡣
�ݹ�Ľ��������������������ͺá�
*/

class Solution {
public:
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

		TreeNode* root = build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
		return root;
	}
	TreeNode* build(vector<int>& preorder, int prestart, int preend, vector<int>& inorder, int instart, int inend)
	{
		if (prestart > preend || instart > inend)//��������
			return nullptr;
		TreeNode* root = new TreeNode(preorder[prestart]);//�ýڵ��ֵ����preorder[prestart]
		int inindex;
		for (int i = instart; i <= inend; ++i)
		{
			if (inorder[i] == preorder[prestart])//�ҵ������У�����ĸ��ڵ��λ��
				inindex = i;
		}
		int len = inindex - instart;//���㻮�ֵ�ǰ�벿������ĳ��ȣ�����Ϊ�����֣�
		root->left = build(preorder, prestart + 1, prestart + len, inorder, instart, inindex - 1);//prestartΪ��ǰ�ڵ��ֵ��������ȥprestart��pre�����prestart + 1 ��ʼ�� prestart + len������in�����instart��ʼ, inindex - 1����
		root->right = build(preorder, prestart + len + 1, preend, inorder, inindex + 1, inend);//��Ϊprestart��pre������ǰ�棬�������������������ں��������ڵģ����������pre�����prestart + len + 1��ʼ����preend������in����inindex + 1��ʼ, inend����
		return root;
	}
};