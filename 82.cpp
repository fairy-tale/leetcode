class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* dummy = new ListNode(INT_MIN);
		dummy->next = head;
		ListNode* last = dummy;
		while (head) {
			int v = head->val;
			ListNode* tmp = head;
			while (head->next && head->next->val == v)
				head = head->next;
			if (tmp == head) {
				last = head;
			}
			else {
				last->next = head->next;
			}
			head = head->next;
		}
		return dummy->next;
	}
};