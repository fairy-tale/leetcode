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
	ListNode* partition(ListNode* head, int x) {
		ListNode* dummy = new ListNode(INT_MIN);
		dummy->next = head;
		head = dummy;
		ListNode* tmp = head, *tail;
		int len = 0, c = 0;
		while (tmp->next) {
			tmp = tmp->next;
			tail = tmp;
			len++;
		}
		//the order need to be same, so the tail also need to be consider.
		while (c < len) {
			if (head->next->val >= x) {
				tail->next = head->next;
				head->next = head->next->next;
				tail = tail->next;
				tail->next = nullptr;
			}
			else {
				head = head->next;
			}
			c++;
		}
		return dummy->next;
	}
};