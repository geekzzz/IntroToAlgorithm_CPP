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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(INT_MIN);
        if(!head)
            return head;
        ListNode * pre = dummy;
        if(!head->next)
            return head;
        dummy->next = head;
        ListNode * cur = head;
        while(cur )
        {
            if(cur->next && cur->val == cur->next->val)
            {
                
                ListNode * p = cur->next;
                while(p && p->val == cur->val)
                {
                    p = p->next;
                }
                //p = p->next;
                pre->next = p;
                cur = pre->next;
            }
            else
            {
                pre = pre->next;
                cur = cur->next;
            }
        }
        return dummy->next;
    }
};
