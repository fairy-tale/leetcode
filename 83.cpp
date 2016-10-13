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
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode* h = head;
		while (head) {
			int v = head->val;
			ListNode* tmp = head;
			while (head->next && head->next->val == v)
				head = head->next;
			tmp->next = head->next;
			head = head->next;
		}
		return h;
	}
};