// left->left = right->right!
class Solution {
public:
	bool isSymmetric(TreeNode* root) {
		if (!root) return true;
		return f(root->left, root->right);
	}

	bool f(TreeNode* left, TreeNode* right) {
		if (!left && !right) {
			return true;
		}
		else if (left && right) {
			return f(left->left, right->right) && f(left->right, right->left) && left->val == right->val;
		}
		else {
			return false;
		}
	}
};