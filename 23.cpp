// divide and conquer logn * nk
class Solution {
public:
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		if (lists.size() == 0) return NULL;
		if (lists.size() == 1) return lists[0];
		vector<ListNode*> left;
		vector<ListNode*> right;
		int n = lists.size();
		for (int i = 0; i < n; ++i) {
			if (i < n / 2) left.push_back(lists[i]);
			else right.push_back(lists[i]);
		}
		ListNode* l = mergeKLists(left);
		ListNode* r = mergeKLists(right);
		return f(l, r);
	}
	ListNode* f(ListNode* l1, ListNode* l2) {
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

// heap  (priority_queue) logn * nk
class Solution {
public:
	// remember this structure for prority_queue!
	struct comp{
		bool operator()(const ListNode* l1, const ListNode* l2) {
			return l1->val > l2->val;
		}
	};
	ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode* dummy = new ListNode(-1);
		priority_queue<ListNode*, vector<ListNode*>, comp> heap;
		for (auto &l : lists)
			if (l) heap.push(l);
		ListNode* head = dummy;
		while (!heap.empty()) {
			ListNode* t = heap.top();
			heap.pop();
			head->next = new ListNode(t->val);
			head = head->next;
			if (t->next) heap.push(t->next);
		}
		return dummy->next;

	}
};