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
	//����һ��constant space
	ListNode* sortList(ListNode* head) {
	int length = 0;
	ListNode * cur = head;
	while(cur)
	{
	length++;
	cur = cur->next;
	}
	ListNode d(0);
	ListNode* dummy = &d;
	dummy->next = head;
	ListNode *tail,*left,*right;

	for(int i = 1;i < length; i <<= 1)//�ֲ�������merge
	{
	cur = dummy->next;
	tail = dummy;
	while(cur)//ÿ���δ���һ��
	{
	left = cur;
	right = split(left,i);
	cur = split(right,i);
	tail = merge(left,right,tail);
	}
	}
	return dummy->next;
	}

	ListNode* split(ListNode* head,int n)//����ָ�ȣ����غ��ε�ͷ
	{
	for(int i = 1;head && i <n;++i)//ע������
	head = head->next;
	if(!head) return NULL;

	ListNode *second = head->next;
	head->next = NULL;
	return second;
	}
	ListNode* merge(ListNode * l1,ListNode * l2,ListNode* head)
	{
	ListNode* cur = head;
	while(l1 && l2)
	{
	if(l1->val > l2->val)
	{
	cur->next = l2;
	cur = l2;
	l2 = l2->next;
	}
	else
	{
	cur->next = l1;
	cur = l1;
	l1 = l1->next;
	}
	}
	cur->next = l1 ? l1 : l2;
	while(cur->next)
	cur = cur->next;
	return cur;
	}
	


	//������ �ݹ鷽����ʵ�ּ򵥣����ǿռ䲻�ǳ���
	ListNode* sortList(ListNode* head) {
		if (!head || !(head->next))
			return head;
		ListNode * slow = head, *fast = head, *pre;
		while (fast && fast->next)
		{
			pre = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		pre->next = NULL;

		ListNode* l1 = sortList(head);
		ListNode* l2 = sortList(slow);
		return merge(l1, l2);
	}

	ListNode* merge(ListNode * l1, ListNode * l2)
	{
		ListNode d(0);
		ListNode * dummy = &d;
		ListNode *p = &d;
		while (l1 && l2)
		{
			if (l1->val > l2->val)
			{
				p->next = l2;
				l2 = l2->next;
			}
			else
			{
				p->next = l1;
				l1 = l1->next;
			}
			p = p->next;
		}
		p->next = l1 ? l1 : l2;
		return dummy->next;
	}












};