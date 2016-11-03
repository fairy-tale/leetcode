//search the left child and put the right child into stack.
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> res;
		while (true) {
			while (root) {
				res.push_back(root->val);
				if (root->right) s.push(root->right);
				root = root->left;
			}
			if (s.empty()) break;
			root = s.top();
			s.pop();
		}
		return res;
	}
};