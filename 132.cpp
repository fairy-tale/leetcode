// O(n^3) tle, too many duplicate caculation when checking the substr whether it is a Palindrome
// O(n^2) solution,  every time choose a center i/i+0.5, search the longest palidrome on this center(using index j). 
// The mincut till the end of i+j could be no larger than the mincut of i-j + 1;
class Solution {
public:
	int minCut(string s) {
		int n = s.size();
		if (n <= 1) return 0;
		vector<int> dp(n + 1, INT_MAX);
		dp[0] = -1;
		for (int i = 0; i < n; ++i) {
			//center : i
			for (int j = 0; i - j >= 0 && i + j < n && s[i - j] == s[i + j]; ++j)
				dp[i + j + 1] = min(dp[i + j + 1], dp[i - j] + 1);
			//center: i+0.5
			for (int j = 1; i - j + 1 >= 0 && i + j < n && s[i - j + 1] == s[i + j]; ++j)
				dp[i + j + 1] = min(dp[i + j + 1], dp[i - j + 1] + 1);
		}
		return dp[n];
	}
};