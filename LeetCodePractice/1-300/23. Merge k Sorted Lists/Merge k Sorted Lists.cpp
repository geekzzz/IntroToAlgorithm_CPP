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

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0)
			return nullptr;
		while (lists.size() > 1)
		{
			lists.push_back(mergeTwoLists(lists[0], lists[1]));
			lists.erase(lists.begin());
			lists.erase(lists.begin());
		}
		return lists[0];
	}
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1)
			return l2;
		if (!l2)
			return l1;
		ListNode* tail = new ListNode(INT_MIN);
		ListNode* head = tail;
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				tail->next = l1;
				l1 = l1->next;
			}
			else
			{
				tail->next = l2;
				l2 = l2->next;
			}
			tail = tail->next;
		}
		tail->next = l1 ? l1 : l2;
		return head->next;
	}

};