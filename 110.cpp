class Solution {
private:
	bool flag = true;
public:
	bool isBalanced(TreeNode* root) {
		f(root);
		return flag;
	}

	int f(TreeNode* root) {
		if (!root) return 0;
		int left = f(root->left);
		int right = f(root->right);
		if (abs(right - left) > 1) flag = false;
		return max(right, left) + 1;
	}
};