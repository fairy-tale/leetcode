//merge sort. complex!
class Solution {
public:
	ListNode* sortList(ListNode* head) {
		ListNode* p = head;
		ListNode* dummy = new ListNode(INT_MIN);
		dummy->next = head;
		int l = 0;
		while (p) {
			p = p->next;
			l++;
		}
		if (l <= 1) return head;
		int k = 1;
		for (int k = 1; k < l; k *= 2) {
			ListNode *pre = dummy;
			p = pre->next;
			while (p) {
				int i = 0;
				ListNode *p1 = p, *p2 = nullptr, *end1 = nullptr, *end2 = nullptr, *tmp = p;
				while (i < 2 * k && tmp) {
					if (i == k) p2 = end1 = tmp;
					tmp = tmp->next;
					i++;
				}
				end2 = tmp;
				while (p1 != end1 && p2 != end2) {
					if (p1->val > p2->val) {
						pre->next = p2;
						p2 = p2->next;
					}
					else {
						pre->next = p1;
						p1 = p1->next;
					}
					pre = pre->next;
				}
				while (p1 != end1) {
					pre->next = p1;
					pre = pre->next;
					p1 = p1->next;
				}
				while (p2 != end2) {
					pre->next = p2;
					pre = pre->next;
					p2 = p2->next;
				}
				pre->next = end2;
				p = end2;
			}
		}
		return dummy->next;
	}
};