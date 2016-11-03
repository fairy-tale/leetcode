class Solution {
public:
	void flatten(TreeNode* root) {
		while (root) {
			if (root->left) {
				if (root->right) {
					TreeNode* t = root->left;
					while (t->right) t = t->right;
					t->right = root->right;
				}
				root->right = root->left;
				root->left = nullptr;
			}
			root = root->right;
		}
	}
};