class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		if (n > 0 && p[0] == '*') return false;
		vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
		dp[0][0] = true;
		for (int i = 1; i <= n; ++i) {
			char c = p[i - 1];
			dp[i][0] = c == '*' ? dp[i - 2][0] : false;
			for (int j = 1; j <= m; ++j) {
				if (c == '.') {
					dp[i][j] = dp[i - 1][j - 1];
				}
				else if (c == '*') {
					dp[i][j] = dp[i - 2][j] || (dp[i][j - 1] && (p[i - 2] == '.' ? true : p[i - 2] == s[j - 1]));
				}
				else {
					if (c == s[j - 1]) dp[i][j] = dp[i - 1][j - 1];
				}

			}
		}
		return dp[n][m];
	}
};