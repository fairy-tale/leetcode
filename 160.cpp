class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *a = headA, *b = headB;
		//if A and B has no intersection, they will meet at nulltpr!
		while (a != b) {
			a = a ? a->next : headB;
			b = b ? b->next : headA;
		}
		return a;
	}
};