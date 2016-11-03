//solution 1
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		if (k >= n / 2) return f(prices);
		vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
		for (int j = 1; j <= k; ++j) {
			int max_in = -prices[0];
			for (int i = 2; i <= n; ++i) {
				dp[i][j] = max(dp[i - 1][j], max_in + prices[i - 1]);
				max_in = max(max_in, dp[i - 1][j - 1] - prices[i - 1]);
			}
		}
		return dp[n][k];
	}
	int f(vector<int> & prices) {
		int ans = 0;
		for (int i = 1; i < prices.size(); ++i)
			if (prices[i] > prices[i - 1])
				ans += prices[i] - prices[i - 1];
		return ans;
	}
};




//solution 2  dp[i][j] = max(dp[i-1][j], dp[i-1][j-1] +/- prices[i]), rolling array
class Solution {
public:
	int maxProfit(int k, vector<int>& prices) {
		int n = prices.size();
		if (k >= n / 2) return f(prices);
		vector<int> dp(2 * k + 1, INT_MIN);
		for (int i = 0; i <= 2 * k; i += 2) dp[i] = 0;
		for (int i = 0; i < n; ++i) {
			//from right to left or left to right doesn't matter. 
			for (int j = 2 * k; j >= 1; --j) {
				if (j % 2) {
					dp[j] = max(dp[j], dp[j - 1] - prices[i]);
				}
				else {
					dp[j] = max(dp[j], dp[j - 1] + prices[i]);
				}
			}
		}
		return dp[2 * k];
	}

	int f(vector<int> & prices) {
		int ans = 0;
		for (int i = 1; i < prices.size(); ++i)
			if (prices[i] > prices[i - 1])
				ans += prices[i] - prices[i - 1];
		return ans;
	}
};