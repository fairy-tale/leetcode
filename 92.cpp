//using pointer to pointer instead of dummy! beautiful!
//do not need use prev->next any more!
class Solution {
public:
	ListNode* reverseBetween(ListNode* head, int m, int n) {
		if (n <= m) return head;
		n -= m;
		// pointer to pointer
		ListNode **pp = &head;
		while (--m)  pp = &(*pp)->next;
		ListNode *cur = *pp, *start = *pp, *ne = cur->next, *tmp;
		while (n--) {
			tmp = ne->next;
			ne->next = cur;
			cur = ne;
			ne = tmp;
		}
		*pp = cur;
		start->next = ne;
		return head;
	}
};