// solution1
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* last, *cur, *next;
		cur = dummy;
		while (cur->next && cur->next->next) {
			last = cur;
			cur = cur->next;
			last->next = cur->next;
			next = cur->next->next;
			cur->next->next = cur;
			cur->next = next;
		}
		return dummy->next;
	}
};

//solution2  iteration
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* tmp = head;
		ListNode* next = head->next->next;
		head = head->next;
		head->next = tmp;
		ListNode* p = swapPairs(next);
		tmp->next = p;
		return head;
	}
};