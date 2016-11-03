//leaf means it doesn't have either left child or right child!
class Solution {
public:
	int sumNumbers(TreeNode* root) {
		int res = 0;
		if (!root) return res;
		dfs(root, 0, res);
		return res;
	}

	void dfs(TreeNode* root, int cur, int &res) {
		cur = cur * 10 + root->val;
		if (!root->left && !root->right) {
			res += cur;
		}
		else {
			if (root->left) dfs(root->left, cur, res);
			if (root->right) dfs(root->right, cur, res);
		}
	}
};