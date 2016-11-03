//iterative	O(1) sapce
class Solution {
public:
	void connect(TreeLinkNode *root) {
		TreeLinkNode* start;
		while (root) {
			start = root->left;
			while (root) {
				if (root->left) root->left->next = root->right;
				if (root->right) root->right->next = root->next ? root->next->left : nullptr;
				root = root->next;
			}
			root = start;
		}
	}
};


//recursive O(log(n)) space

class Solution {
public:
	void connect(TreeLinkNode *root) {
		if (!root) return;
		if (root->left) root->left->next = root->right;
		if (root->right && root->next) root->right->next = root->next->left;
		connect(root->left);
		connect(root->right);
	}
};
