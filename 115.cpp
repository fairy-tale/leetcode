// a little weird..
// dp[i][j] = (s[i-1] == t[j-1])? dp[i-1][j]+dp[i-1][j-1] : dp[i-1][j]
//dp[i][j] means end of s: i, end of t: j
class Solution {
public:
	int numDistinct(string s, string t) {
		int n = t.size();
		int m = s.size();
		vector<int> dp(n + 1, 0);
		dp[0] = 1;
		for (int i = 0; i < m; ++i) {
			// from left to right, it will overwrite the result before!  from right to left!
			for (int j = n; j >= 1; --j) {
				if (s[i] == t[j - 1]) {
					dp[j] += dp[j - 1];
				}
			}
		}
		return dp[n];
	}
};