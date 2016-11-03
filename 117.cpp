//start: first node of each level
class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		TreeLinkNode* start = root;
		while (start) {
			TreeLinkNode *q = start, *cur = nullptr;
			start = nullptr;
			while (q){
				if (q->left && q->right) {
					if (!start) start = q->left;
					q->left->next = q->right;
					cur = q->right;
				}
				else {
					cur = q->left ? q->left : q->right;
					if (!start && cur) start = cur;
				}
				if (cur) {
					TreeLinkNode* tmp = q->next, *next = nullptr;
					while (tmp) {
						if (tmp->left) {
							next = tmp->left;
							break;
						}
						if (tmp->right) {
							next = tmp->right;
							break;
						}
						tmp = tmp->next;
					}
					cur->next = next;
					q = tmp;
				}
				else {
					q = q->next;
				}
			}
		}
	}
};