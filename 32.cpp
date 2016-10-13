//stack
class Solution {
public:
	int longestValidParentheses(string s) {
		stack<int> st;
		int max_len = 0;
		int start = 0;
		for (int i = 0; i < s.size(); ++i) {
			if (s[i] == '(') {
				st.push(i);
			}
			else {
				if (!st.empty()) {
					st.pop();
					int cur_len = st.empty() ? i + 1 - start : i - st.top();
					max_len = max(max_len, cur_len);
				}
				else {
					start = i + 1;
				}
			}
		}
		return max_len;

	}
};


//dp
class Solution {
public:
	int longestValidParentheses(string s) {
		int m = s.size();
		int res = 0;
		vector<int> dp(m, 0);
		for (int i = 1; i < m; ++i) {
			if (s[i] == ')') {
				if (s[i - 1] == '(') {
					dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
				}
				else {
					int k = i - 1 - dp[i - 1];
					if (k >= 0 && s[k] == '(') {
						dp[i] += k ? dp[k - 1] : 0;
						dp[i] += dp[i - 1] + 2;
					}
				}
				res = max(res, dp[i]);
			}
		}
		return res;
	}
};