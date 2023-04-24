/*
 * @lc app=leetcode.cn id=23 lang=cpp
 *
 * [23] 合并 K 个升序链表
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        return mergeKLists(lists,0, lists.size() - 1);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists, int start, int end) {
        if(start == end)
        {
            return lists[start];
        }
        if(start > end)
        {
            return nullptr;
        }
        int mid = (start + end) / 2;
        return mergeTwoLists(mergeKLists(lists, start, mid),mergeKLists(lists, mid + 1, end));
    }

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

