class Solution {
public:
	int numDecodings(string s) {
		int n = s.size();
		if (!n) return 0;
		vector<int> dp(n + 1, 0);
		if (s[0] == '0') return 0;
		dp[0] = 1;
		for (int i = 1; i < n; ++i) {
			if (s[i] == '0') {
				if (s[i - 1] >= '3' || s[i - 1] == '0') return 0;
				else dp[i] = i >= 2 ? dp[i - 2] : 1;
			}
			else {
				dp[i] = dp[i - 1];
				if (s[i - 1] == '1' || s[i - 1] == '2' && s[i] <= '6')
					dp[i] += i >= 2 ? dp[i - 2] : 1;
			}
		}
		return dp[n - 1];
	}
};