class Solution {
public:
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> res;
		vector<int> v;
		if (root) f(root, sum, res, v);
		return res;
	}
	void f(TreeNode* root, int sum, vector<vector<int>>& res, vector<int>& v) {
		v.push_back(root->val);
		if (!root->left && !root->right) {
			if (sum == root->val) res.push_back(v);
		}
		else {
			if (root->left) f(root->left, sum - root->val, res, v);
			if (root->right) f(root->right, sum - root->val, res, v);
		}
		v.pop_back();
	}
};