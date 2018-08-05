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
	ListNode* reverseList(ListNode* head) {
		if (head == NULL)
		{
			return NULL;
		}
		auto hp = new ListNode(head->val);
		if (head->next == NULL)
			return hp;
		hp->next = NULL;
		auto p = head->next;
		while (p->next != NULL)
		{
			auto n = new ListNode(p->val);
			n->next = hp;
			hp = n;
			p = p->next;
		}
		auto n = new ListNode(p->val);
		n->next = hp;
		return n;
	}
};