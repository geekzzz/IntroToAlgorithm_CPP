/*
 * @lc app=leetcode.cn id=21 lang=cpp
 *
 * [21] 合并两个有序链表
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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* dummy = new ListNode();
        ListNode* p = dummy;
        while(list1 && list2)
        {
            if(list1->val < list2->val)
            {
                p->next = list1;
                list1 = list1->next;
            }
            else
            {
                p->next = list2;
                list2 = list2->next;
            }
            p = p->next;
        }
        while(list1)
        {
            p->next = list1;
            list1 = list1->next;
            p = p->next;
        }
        while(list2)
        {
            p->next = list2;
            list2 = list2->next;
            p = p ->next;
        }
        return dummy->next;
    }
};
// @lc code=end

