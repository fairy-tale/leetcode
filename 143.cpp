// reverse the second half of the list, then pair the listnode of the first half and the second half one by one.
class Solution {
public:
	void reorderList(ListNode* head) {
		if (!head) return;
		ListNode *slow = head, *fast = head, *last = nullptr, *next, *prev;
		bool flag = true;
		while (fast && fast->next) {
			fast = fast->next->next;
			prev = slow;
			slow = slow->next;
		}
		if (!fast) flag = false;
		if (flag) slow = slow->next;
		while (slow) {
			next = slow->next;
			slow->next = last;
			last = slow;
			slow = next;
		}
		slow = head;
		while (last) {
			ListNode* tmp = last->next;
			next = slow->next;
			slow->next = last;
			last->next = next;
			last = tmp;
			slow = next;
		}
		//need to let the last node of first half point to null;
		slow->next = nullptr;
	}
};