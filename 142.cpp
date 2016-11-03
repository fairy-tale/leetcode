//after two pointer meet, then change the step of the fast to 1
//let the slow back to head, the first time they meet,
//it is the start point of circle
//t: len before circle, k: len of circle, c: len from the start point of circle to the point they meet.
// 2*(t + c + n1 * k) = t + c + n2 * k                    t + c = n3*k
//so after slow goes t + c again, it will meet fast at the point they meet the first time. 
//Since now the step of two pointer are both 1, the first point they meet the second time is the circle start point.
class Solution {
public:
	ListNode *detectCycle(ListNode *head) {
		ListNode *fast = head, *slow = head;
		while (fast && fast->next) {
			fast = fast->next->next;
			slow = slow->next;
			if (slow == fast) break;
		}
		if (!fast || !fast->next) return nullptr;
		slow = head;
		while (slow != fast) {
			fast = fast->next;
			slow = slow->next;
		}
		return slow;
	}
};