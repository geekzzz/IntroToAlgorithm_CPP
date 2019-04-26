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
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		ListNode * dummy = new ListNode(0);
		dummy->next = head;
		ListNode *pre = dummy, *cur;

		for (int i = 0; i < m - 1; ++i)
		{
			pre = pre->next;
		}
		cur = pre->next;
		for (int i = 0; i < n - m; ++i)//注意，这个是头插法翻转链表的4句代码，一定要背下来
		{
			ListNode* tmp = pre->next;
			pre->next = cur->next;
			cur->next = cur->next->next;
			pre->next->next = tmp;
		}
		return dummy->next;
	}
};