class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums) {
		return f(&*nums.begin(), &*nums.end());
	}
	TreeNode* f(int *start, int *end) {
		if (start == end) return NULL;
		int *mid = start + (end - start) / 2;
		TreeNode* root = new TreeNode(*mid);
		root->left = f(start, mid);
		root->right = f(mid + 1, end);
		return root;
	}
};