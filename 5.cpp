class Solution {
public:
	string longestPalindrome(string s) {
		vector<int> r(s.size() * 2 + 1, 0);
		string s1(s.size() * 2 + 1, '#');
		for (int i = 0; i < s.size(); ++i) s1[i * 2 + 1] = s[i];
		int max_len = 0, max_mid = 0, cur_mid = 0, cur_end = 0;
		for (int i = 0; cur_end != s1.size() - 1; ++i) {
			int tmp = r[2 * cur_mid - i];
			if (tmp + i < cur_end) {
				r[i] = tmp;
				continue;
			}
			while (++cur_end < s1.size() && 2 * i - cur_end >= 0 && s1[cur_end] == s1[2 * i - cur_end]);
			r[i] = --cur_end - i;
			cur_mid = i;
			if (max_len < cur_end - i) {
				max_mid = cur_mid;
				max_len = r[cur_mid];
			}
		}
		string ans;
		ans = s.substr((max_mid - max_len) / 2, max_len);
		return ans;
	}
};