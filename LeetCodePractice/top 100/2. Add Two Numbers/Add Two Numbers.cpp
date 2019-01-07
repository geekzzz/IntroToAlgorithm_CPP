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
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int c = 0;
		ListNode*l = new ListNode(0);
		ListNode*p = l;
		while (l1 || l2 || c)
		{
			int result = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + c;
			p->next = new ListNode(result % 10);
			p = p->next;
			c = result / 10;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
		}
		return l->next;
	}
};