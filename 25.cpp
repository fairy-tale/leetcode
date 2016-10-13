//o(1) space
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* last = dummy;
		while (head) {
			ListNode* p = head, *p2 = head;
			int k1 = k;
			for (; k1 > 0 && p; --k1)  p = p->next;
			if (k1) break;
			ListNode* next = p;
			for (int i = k; i > 0; --i) {
				ListNode* tmp = head->next;
				head->next = next;
				next = head;
				head = tmp;
			}
			last->next = next;
			last = p2;
			head = p;
		}
		return dummy->next;

	}
};

// o(n) space but very concise solution using recursion.
class Solution {
public:
	ListNode* reverseKGroup(ListNode* head, int k) {
		ListNode* p = head;
		for (int i = k; i > 0; --i) {
			if (!p) return head;
			p = p->next;
		}
		ListNode* next = reverseKGroup(p, k);
		for (int i = k; i > 0; --i) {
			ListNode* tmp = head->next;
			head->next = next;
			next = head;
			head = tmp;
		}
		return next;

	}
};