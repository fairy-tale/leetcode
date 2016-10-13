class Solution {
public:
	string multiply(string num1, string num2) {
		int m = num1.size();
		int n = num2.size();
		string res = "";
		vector<int> ans((n + 1)*(m + 1), 0);
		int step = 0;
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				step = (num1[m - i - 1] - '0') * (num2[n - j - 1] - '0');
				int k = i + j;
				ans[k] += step;
				ans[k + 1] += ans[k] / 10;
				ans[k] %= 10;
			}
		}
		int t = n + m + 1;
		while (!ans[t]) t--;
		for (int i = t; i >= 0; --i)
			res += (ans[i] + '0');
		if (res == "") res += "0";
		return res;
	}
};