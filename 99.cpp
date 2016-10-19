// inorder O(n) space if using recursion
// Morris inorder O(1) space
class Solution {
private:
	TreeNode *p = nullptr;
public:
	void recoverTree(TreeNode* root) {
		TreeNode *p1 = nullptr, *p2 = nullptr, *prev = nullptr;
		while (root){
			TreeNode* t = root->left;
			if (t) {
				while (t->right && t->right != root)
					t = t->right;
				if (!t->right) {
					t->right = root;
					root = root->left;
					continue;
				}
				else {
					t->right = nullptr;
				}
			}
			if (prev && prev->val > root->val) {
				if (!p1) {
					p1 = prev;
					p2 = root;
				}
				else {
					p2 = root;
					// can't add break here! because the tree has been modified, it need a whole search to rebuild.
					//break;
				}
			}
			prev = root;
			root = root->right;
		}
		swap(p1->val, p2->val);
	}
};