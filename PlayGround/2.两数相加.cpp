/*
 * @lc app=leetcode.cn id=2 lang=cpp
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		int c = 0;
		ListNode *head = new ListNode();
		ListNode* node = head;
		while(l1 || l2 || c)
		{
			int v =  (l1 ? l1->val:0) + (l2 ? l2->val :0) + c;
			node->val = v%10;
			c = v/10;
			l1 = l1 ? l1->next : l1;
			l2 = l2 ? l2->next : l2;
			if(l1 || l2 || c)
			{
				ListNode * newNode = new ListNode();
				node->next = newNode;
				node = newNode;
			}
		}
		return head;
    }
};
// @lc code=end

