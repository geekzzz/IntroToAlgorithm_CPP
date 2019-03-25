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
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int n = nums.size();
		if (!n)
			return NULL;
		return help(0, n - 1, nums);
	}
	TreeNode * help(int start, int end, vector<int>& nums)
	{
		int n = end - start;
		if (n < 0)
			return NULL;
		if (n == 0)
			return new TreeNode(nums[start]);
		int mid = (start + end) / 2;
		TreeNode * root = new TreeNode(nums[mid]);
		root->left = help(start, mid - 1, nums);
		root->right = help(mid + 1, end, nums);
		return root;
	}
};