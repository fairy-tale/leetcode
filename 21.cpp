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
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1) return l2;
		if (!l2) return l1;
		ListNode* dummy = new ListNode(INT_MIN);
		ListNode* p = dummy;
		int v1 = l1->val;
		int v2 = l2->val;
		while (true) {
			if (v1 < v2) {
				p->next = new ListNode(v1);
				p = p->next;
				l1 = l1->next;
				if (!l1) {
					p->next = l2;
					break;
				}
				else {
					v1 = l1->val;
				}
			}
			else {
				p->next = new ListNode(v2);
				p = p->next;
				l2 = l2->next;
				if (!l2) {
					p->next = l1;
					break;
				}
				else {
					v2 = l2->val;
				}
			}
		}
		return dummy->next;
	}
};