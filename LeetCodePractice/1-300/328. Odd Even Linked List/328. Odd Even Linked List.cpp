/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//�Լ��Ľⷨ���о����ǱȽ��鷳
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		ListNode* dummy1 = new ListNode(0);
		ListNode* dummy2 = new ListNode(0);
		ListNode* p1 = dummy1;
		ListNode* p2 = dummy2;
		bool flag = false;
		while (head)
		{
			if (!flag)
			{
				p1->next = head;
				p1 = p1->next;
				head = head->next;
				p1->next = nullptr;
				flag = !flag;
			}
			else
			{
				p2->next = head;
				p2 = p2->next;
				head = head->next;
				p2->next = nullptr;
				flag = !flag;
			}

		}
		p1->next = dummy2->next;
		return dummy1->next;
	}
};
//����һ��Ľⷨ
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {
		if (!head)
			return nullptr;
		ListNode* odd = head;
		ListNode* even = head->next;
		ListNode* evenhead = even;
		while (even && even->next)
		{
			odd->next = odd->next->next;
			even->next = even->next->next;

			even = even->next;
			odd = odd->next;
		}
		odd->next = evenhead;
		return head;
	}
};