class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		if (!root) return false;
		if (!root->left && !root->right) {
			return sum == root->val;
		}
		else {
			bool flag = false;
			if (root->left) flag = flag || hasPathSum(root->left, sum - root->val);
			if (root->right) flag = flag || hasPathSum(root->right, sum - root->val);
			return flag;
		}
	}
};