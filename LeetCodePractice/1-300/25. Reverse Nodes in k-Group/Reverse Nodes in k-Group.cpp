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

	ListNode* reverseKGroup(ListNode* head, int k) {
		if (!head || k == 1)
			return head;
		ListNode* dum = new ListNode(INT_MIN);
		dum->next = head;
		ListNode* pre = dum;
		ListNode* cur = dum;
		ListNode* next = cur->next;
		int num = 0;
		while (cur = cur->next)
			num++;
		while (num >= k)
		{
			cur = pre->next;
			next = cur->next;
			for (int i = 1; i < k; ++i)
			{
				cur->next = next->next;
				next->next = pre->next;
				pre->next = next;
				next = cur->next;
			}
			pre = cur;
			num -= k;
		}
		return dum->next;
	}