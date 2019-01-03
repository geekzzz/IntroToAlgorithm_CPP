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

	ListNode* swapPairs(ListNode* head) {
		if (!head)
			return nullptr;
		ListNode* dum = new ListNode(INT_MIN);
		dum->next = head;
		ListNode* cur = head;
		ListNode* pre = dum;
		while (cur && cur->next)
		{
			pre->next = cur->next;
			pre = cur->next;
			cur->next = pre->next;
			pre->next = cur;
			pre = cur;
			cur = cur->next;
		}
		return dum->next;
	}

};