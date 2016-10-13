class Solution {
public:
	string convert(string s, int numRows) {
		int k = numRows * 2 - 2;
		if (k <= 0) return s;
		string ans = "";
		int r = 0;
		while (r < numRows) {
			int tmp = r;
			while (tmp < s.size()) {
				ans += s[tmp];
				if (r != 0 && r != numRows - 1 && tmp + k - 2 * r < s.size()) ans += s[tmp + k - 2 * r];
				tmp += k;
			}
			++r;
		}
		return ans;
	}
};