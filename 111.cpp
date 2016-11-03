class Solution {
public:
	int minDepth(TreeNode* root) {
		if (!root) return 0;
		queue<TreeNode*> q;
		q.push(root);
		int l = 0;
		bool flag = true;
		while (flag) {
			l++;
			int n = q.size();
			for (int i = 0; i < n; ++i) {
				TreeNode* p = q.front();
				q.pop();
				if (!p->left && !p->right) {
					flag = false;
					break;
				}
				if (p->left) q.push(p->left);
				if (p->right) q.push(p->right);
			}
		}
		return l;
	}
};