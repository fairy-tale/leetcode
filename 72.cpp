// use rolling array could reduce the space complexity to O(n) 
class Solution {
public:
	int minDistance(string word1, string word2) {
		int m = word1.size();
		int n = word2.size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= n; ++i) dp[0][i] = i;
		for (int i = 1; i <= m; ++i) {
			dp[i][0] = i;
			for (int j = 1; j <= n; ++j) {
				// when word1[i-1] == word2[j-1], dp[i-1][j-1] must be the smallest one compared tp dp[i-1][j]+1, dp[i][j-1]+1
				dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1; 
				dp[i][j] = min(dp[i][j], word1[i - 1] == word2[j - 1] ? dp[i - 1][j - 1] : dp[i - 1][j - 1] + 1);
			}
		}
		return dp[m][n];
	}
};