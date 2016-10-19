class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int m = s1.size();
		int n = s2.size();
		int l = s3.size();
		if (l != m + n) return false;
		vector<vector<bool>> dp(m + 1, vector<bool>(n + 1, false));
		dp[0][0] = true;
		for (int i = 0; i < m + n; ++i) {
			for (int j = max(0, i - n); j <= min(i, m); ++j) {
				if (dp[j][i - j]) {
					if (s3[i] == s1[j]) {
						dp[j + 1][i - j] = true;
					}
					if (s3[i] == s2[i - j]) {
						dp[j][i - j + 1] = true;
					}
				}
			}
		}
		return dp[m][n];
	}
};