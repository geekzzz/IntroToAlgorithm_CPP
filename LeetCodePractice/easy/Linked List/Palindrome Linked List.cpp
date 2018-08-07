/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return true;
		ListNode* slow = head;
		ListNode* fast = head;
		while (fast->next != NULL && fast->next->next != NULL)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		slow->next = ReverseList(slow->next);
		slow = slow->next;
		while (slow)
		{
			if (slow->val != head->val)
				return false;
			slow = slow->next;
			head = head->next;
		}
		return true;
	}

	ListNode* ReverseList(ListNode* head)
	{
		ListNode* pre = NULL;
		ListNode* next = NULL;
		while (head)
		{
			next = head->next;
			head->next = pre;
			pre = head;
			head = next;
		}
		return pre;
	}
};