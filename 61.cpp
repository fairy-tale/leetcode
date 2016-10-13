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
	ListNode* rotateRight(ListNode* head, int k) {
		ListNode* fast = head;
		ListNode* end;
		int len = 0;
		while (fast) {
			len++;
			if (!fast->next) end = fast;
			fast = fast->next;
		}
		if (!len) return head;
		fast = head;
		k %= len;
		if (!k) return head;
		k = len - k;
		ListNode* last;
		for (int i = 0; i < k; ++i) {
			last = fast;
			fast = fast->next;
		}
		end->next = head;
		head = fast;
		last->next = nullptr;
		return head;
	}
};