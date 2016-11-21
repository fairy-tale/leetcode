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
	ListNode* removeElements(ListNode* head, int val) {
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		head = dummy;
		while (head && head->next) {
			if (head->next->val == val)
				head->next = head->next->next;
			else
				head = head->next;
		}
		return dummy->next;
	}
};

//pointer to pointer
class Solution {
public:
	ListNode* removeElements(ListNode* head, int val) {
		ListNode **p = &head;
		// here we need to use *p!!! since even *p is null, it still has a address.
		while (*p) {
			if ((*p)->val == val) *p = (*p)->next;
			else p = &(*p)->next;
		}
		return head;
	}
};