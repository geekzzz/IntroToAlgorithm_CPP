/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
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
	TreeNode* sortedListToBST(ListNode* head) {
		return help(head, nullptr);
	}

	TreeNode* help(ListNode* head, ListNode* tail)
	{
		if (head == tail)
			return NULL;
		if (head->next == tail)
			return new TreeNode(head->val);
		ListNode* mid = head, *tmp = head;
		while (tmp != tail && tmp->next != tail)
		{
			mid = mid->next;
			tmp = tmp->next->next;
		}
		TreeNode * root = new TreeNode(mid->val);
		root->left = help(head, mid);
		root->right = help(mid->next, tail);
		return root;
	}
};