class Solution {
public:
	bool wordBreak(string s, unordered_set<string>& wordDict) {
		int n = s.size();
		if (!n) return false;
		vector<bool> dp(n + 1, false);
		dp[0] = true;
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j <= i; ++j) {
				string t = s.substr(j, i - j + 1);
				if (wordDict.count(t) && dp[j]) dp[i + 1] = true;
			}
		}
		return dp[n];
	}
};