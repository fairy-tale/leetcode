class Solution {
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> res;
		string v = "";
		int n = s.size();
		f(s, n, 4, 0, v, res);
		return res;
	}

	void f(string s, int n, int left, int start, string v, vector<string>& res) {
		if (!left && start == n) {
			res.push_back(v);
		}
		else if (n - start <= 3 * left && n - start >= left) {
			int value = 0;
			for (int i = start; i <= start + 2; ++i) {
				value *= 10;
				value += s[i] - '0';
				if (value <= 255 && (s[start] != '0' || (s[start] == '0' && i == start))) {
					string tmp = s.substr(start, i - start + 1);
					string v1 = v;
					v1 += left == 1 ? tmp : tmp + '.';
					f(s, n, left - 1, i + 1, v1, res);
				}
			}
		}
	}
};