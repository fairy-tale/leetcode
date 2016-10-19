//using stack to store the root
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> s;
		vector<int> res;
		TreeNode* p = root;
		while (true) {
			while (p) {
				s.push(p);
				p = p->left;
			}
			if (s.empty()) break;
			p = s.top();
			s.pop();
			res.push_back(p->val);
			p = p->right;
		}
		return res;
	}
};