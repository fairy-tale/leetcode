
class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		ListNode *last, *next;
		last = NULL;
		while (head) {
			next = head->next;
			head->next = last;
			last = head;
			head = next;
		}
		return last;
	}
};