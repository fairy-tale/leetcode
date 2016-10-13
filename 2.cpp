class Solution {
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* head = l1;
		ListNode* dummy1 = new ListNode(INT_MAX);
		ListNode* dummy2 = new ListNode(INT_MAX);
		int step = 0;
		dummy1->next = l1;
		dummy2->next = l2;
		l1 = dummy1;
		l2 = dummy2;
		while (l1->next || l2->next || step) {
			int tmp = (l1->next ? l1->next->val : 0) + (l2->next ? l2->next->val : 0) + step;
			if (!l1->next)
				l1->next = new ListNode(tmp % 10);
			else
				l1->next->val = tmp % 10;
			step = tmp / 10;
			l1 = l1->next ? l1->next : l1;
			l2 = l2->next ? l2->next : l2;
		}
		return head;
	}
};