//recursive solution is easy, f(start, end) = {f(start,k-1)-k-f(k+1,end)},
//then it could turn to a dp solution.
class Solution {
public:
	vector<TreeNode*> generateTrees(int n) {
		vector<TreeNode*> res;
		vector<TreeNode*> dummy(1, nullptr);
		if (!n) return res;
		vector<vector<vector<TreeNode*>>> dp(n + 1, vector<vector<TreeNode*>>(n + 1));
		for (int k = 0; k < n; ++k) {
			for (int i = 1; i + k <= n; ++i) {
				for (int j = i; j <= i + k; ++j) {
					vector<TreeNode*> left_list = i > j - 1 ? dummy : dp[i][j - 1];
					vector<TreeNode*> right_list = j + 1 > i + k ? dummy : dp[j + 1][i + k];
					for (auto &left : left_list) {
						for (auto &right : right_list) {
							TreeNode* p = new TreeNode(j);
							p->left = left;
							p->right = right;
							dp[i][i + k].push_back(p);
						}
					}
				}
			}
		}
		return dp[1][n];
	}
};