class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		stack<pair<TreeNode*, int>> st;
		vector<int> res;
		int maxlevel = 0;
		if (!root) return res;
		st.push(make_pair(root, 1));
		while (!st.empty()) {
			pair<TreeNode*, int> p = st.top();
			st.pop();
			if (p.second > maxlevel) {
				res.push_back(p.first->val);
				maxlevel++;
			}
			if (p.first->left) st.push(make_pair(p.first->left, p.second + 1));
			if (p.first->right) st.push(make_pair(p.first->right, p.second + 1));
		}
		return res;
	}
};

//level order
class Solution {
public:
	vector<int> rightSideView(TreeNode* root) {
		queue<TreeNode*> q;
		vector<int> res;
		if (!root) return res;
		q.push(root);
		while (!q.empty()) {
			res.push_back(q.back()->val);
			int n = q.size();
			for (int i = 0; i < n; ++i) {
				TreeNode* p = q.front();
				q.pop();
				if (p->left) q.push(p->left);
				if (p->right) q.push(p->right);
			}
		}
		return res;
	}
};