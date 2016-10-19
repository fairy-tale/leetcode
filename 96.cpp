//same as 95.
class Solution {
public:
	int numTrees(int n) {
		vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
		if (!n) return 0;
		for (int k = 0; k < n; ++k) {
			for (int i = 1; i + k <= n; ++i) {
				for (int j = i; j <= i + k; ++j) {
					int left = i <= j - 1 ? dp[i][j - 1] : 1;
					int right = j + 1 <= i + k ? dp[j + 1][i + k] : 1;
					dp[i][i + k] += left * right;
				}
			}
		}
		return dp[1][n];
	}
};