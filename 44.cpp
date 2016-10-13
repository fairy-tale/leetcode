// greedy? o(m*n), worst case s = "aaaaaaaaaaaaaa" p = "*aaaaa"
class Solution {
public:
	bool isMatch(string s, string p) {
		int m = s.size();
		int n = p.size();
		int i = 0, j = 0;
		int sstar = -1, pstar = -1;
		while (i < m) {
			if ((p[j] == '?' || p[j] == s[i])) {
				j++;
				i++;
			}
			else if (p[j] == '*') {
				pstar = ++j;
				sstar = i;
			}
			else if (pstar >= 0) {
				i = ++sstar;
				j = pstar;
			}
			else {
				return false;
			}
		}
		while (j < n && p[j] == '*') j++;
		return j == n;
	}
};