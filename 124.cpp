class Solution {
private:
	int res = INT_MIN;
public:
	int maxPathSum(TreeNode* root) {
		f(root);
		return res;
	}

	int f(TreeNode* root) {
		if (!root) return 0;
		int left = f(root->left);
		int right = f(root->right);
		int v = root->val;
		if (left > 0) v += left;
		if (right > 0) v += right;
		res = max(res, v);
		return root->val + max(max(left, right), 0);
	}
};