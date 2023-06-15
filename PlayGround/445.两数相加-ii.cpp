/*
 * @lc app=leetcode.cn id=445 lang=cpp
 *
 * [445] 两数相加 II
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
        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;


        ListNode* l11 = reverse(l1);
        ListNode* l22 = reverse(l2);


        int c = 0;
        while (l11 && l22)
        {
            int res = l11->val + l22->val + c;
            cur->next = new ListNode(res % 10);
            c = res / 10;
            cur = cur->next;
            l11 = l11->next;
            l22 = l22->next;
        }
        while (l11 )
        {
            int res = l11->val + c;
            cur->next = new ListNode(res % 10);
            c = res / 10;
            cur = cur->next;
            l11 = l11->next;
        }
        
        while (l22)
        {
            int res = l22->val + c;
            cur->next = new ListNode(res % 10);
            c = res / 10;
            cur = cur->next;
            l22 = l22->next;
        }
        if(c != 0)
        {
            cur->next = new ListNode(c);
        }
        return reverse(dummy->next) ;
    }

    ListNode* reverse(ListNode* l)
    {
        ListNode* dummy = new ListNode();
        ListNode* cur = l;
        while (cur)
        {
            ListNode* tmp = cur->next;
            cur->next = dummy->next;
            dummy->next = cur;
            cur = tmp;
        }
        return dummy->next;
    }
};
// @lc code=end

