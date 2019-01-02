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
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head)
			return nullptr;
		ListNode* new_head = new ListNode(-1);
		new_head->next = head;
		ListNode* p = new_head;
		ListNode* l = new_head;

		for (int i = 0; i < n; ++i)
		{
			p = p->next;
		}
		while (p->next)
		{
			l = l->next;
			p = p->next;
		}
		ListNode* del = l->next;
		l->next = l->next->next;
		delete del;
		return new_head->next;
	}
};