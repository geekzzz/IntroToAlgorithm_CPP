/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//��ȫ��д��
class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* next = node->next;
		*node = *next;
		delete next;
	}
};

//��򵥣��ڴ�й©
class Solution {
public:
	void deleteNode(ListNode* node) {
		*node = *node->next;
	}
};