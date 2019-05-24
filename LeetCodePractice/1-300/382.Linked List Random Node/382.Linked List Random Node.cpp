class Solution {
public:
	/** @param head The linked list's head.
	Note that the head is guaranteed to be not null, so it contains at least one node. */
	ListNode* h;
	Solution(ListNode* head) {
		h = head;
	}

	/** Returns a random node's value. */
	int getRandom() {
		int res = h->val;
		int i = 1;
		ListNode * cur = h;
		while (cur)
		{
			int k = rand() % i;
			if (k == 0)
				res = cur->val;
			i++;
			cur = cur->next;
		}
		return res;
	}
};