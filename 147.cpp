//the introduction of insertion sort
//https://en.wikipedia.org/wiki/Insertion_sort
class Solution {
public:
	ListNode* insertionSortList(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode **cur, *p, *q;
		p = head;
		q = p->next;
		while (q) {
			if (q->val < p->val) {
				cur = &head;
				p->next = q->next;
				while ((*cur)->val < q->val) {
					cur = &(*cur)->next;
				}
				q->next = *cur;
				// here ,  cur = &q is totally wrong!!    this make the cur with the same address with pointer q. 
				// But what we want is value in cur address to be pointer q
				*cur = q;
			}
			p = q;
			q = p->next;
		}
		return head;
	}
};