//all of the nodes in leftside is smaller than root!!
//LONG_MIN, LONG_MAX to avoid exceeding int range.
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		return f(root, LONG_MIN, LONG_MAX);
	}

	bool f(TreeNode* root, long low, long high) {
		if (!root) return true;
		bool flag = true;
		long value = root->val;
		flag = flag && (value > low) && (value < high);
		flag = flag && f(root->left, low, min(high, value)) && f(root->right, max(low, value), high);
		return flag;
	}
};