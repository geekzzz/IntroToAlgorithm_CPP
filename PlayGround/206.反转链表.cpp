/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
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
    ListNode* reverseList(ListNode* head) {
        ListNode* dummy = new ListNode();
        dummy->next = head;
        ListNode* next = dummy;
        ListNode* cur = head;
        while(cur && cur->next)
        {
            next = cur->next;
            cur->next = cur->next->next;
            next->next = dummy->next;
            dummy->next = next;
        }
        return dummy->next;
    }
};
// @lc code=end

