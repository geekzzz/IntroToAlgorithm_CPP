/*
 * @lc app=leetcode.cn id=83 lang=cpp
 *
 * [83] 删除排序链表中的重复元素
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = head;
        ListNode* next = head ? head->next : nullptr;
        while(next)
        {
            if(pre->val == next->val)
            {
                pre->next = next->next;
                next = pre->next;
            }
            else 
            {
                pre = pre->next;
                next = pre ? pre->next : nullptr;
            }
            
        }
        return head;
    }
};
// @lc code=end

