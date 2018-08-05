/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
//安全的写法
class Solution {
public:
	void deleteNode(ListNode* node) {
		ListNode* next = node->next;
		*node = *next;
		delete next;
	}
};

//最简单，内存泄漏
class Solution {
public:
	void deleteNode(ListNode* node) {
		*node = *node->next;
	}
};