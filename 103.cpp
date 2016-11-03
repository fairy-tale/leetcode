class Solution {
public:
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		queue<TreeNode*> q;
		vector<vector<int>> res;
		if (!root) return res;
		q.push(root);
		while (!q.empty()) {
			int l = q.size();
			vector<int> ans;
			for (int i = 0; i < l; ++i) {
				TreeNode* p = q.front();
				q.pop();
				ans.push_back(p->val);
				if (p->left) q.push(p->left);
				if (p->right) q.push(p->right);
			}
			res.push_back(ans);
		}
		for (int i = 1; i < res.size(); i += 2) {
			reverse(res[i].begin(), res[i].end());
		}
		return res;
	}
};