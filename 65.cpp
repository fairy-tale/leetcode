class Solution {
public:
	bool isNumber(string s) {
		int n = s.size();
		int start = 0, end = n - 1;
		while (start < n && s[start] == ' ') start++;
		while (end >= 0 && s[end] == ' ') end--;
		if (end < start) return false;
		s = s.substr(start, end - start + 1);
		bool valid_end = false;
		bool has_digit = false;
		bool has_dot = false;
		bool has_e = false;
		for (int i = 0; i < s.size(); ++i) {
			char c = s[i];
			if (isdigit(c)) {
				valid_end = true;
				has_digit = true;
			}
			else if (c == 'e') {
				if (!has_digit || has_e) return false;
				valid_end = false;
				has_e = true;
			}
			else if (c == '+' || c == '-') {
				if (i && s[i - 1] != 'e') return false;
				valid_end = false;
			}
			else if (c == '.') {
				if (has_e || has_dot) return false;
				if (i && isdigit(s[i - 1])) {
					valid_end = true;
				}
				else {
					valid_end = false;
				}
				has_dot = true;
			}
			else{
				return false;
			}
		}
		return valid_end;
	}
};
