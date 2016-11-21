class Solution {
public:
	void reverseWords(string &s) {
		int i = 0, j = 0;
		for (; i < s.size(); ++i) {
			if (s[i] != ' ' || (j && s[j - 1] != ' ')) {
				s[j++] = s[i];
			}
		}
		if (j && s[j - 1] == ' ') j--;
		s.resize(j);
		reverse(s.begin(), s.end());
		s += " ";
		int start = 0;
		for (int k = 0; k < s.size(); ++k) {
			if (s[k] == ' ') {
				reverse(s.begin() + start, s.begin() + k);
				start = k + 1;
			}
		}
		s.resize(j);
		return;
	}
};