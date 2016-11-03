class Solution {
public:
	vector<vector<string>> partition(string s) {
		vector<string> cur;
		vector<vector<string>> res;
		f(s, 0, res, cur);
		return res;
	}

	void f(string &s, int index, vector<vector<string>>& res, vector<string>& cur) {
		if (index == s.size()) {
			res.push_back(cur);
		}
		else {
			for (int i = index; i < s.size(); ++i) {
				string t = s.substr(index, i - index + 1);
				if (check(t)) {
					cur.push_back(t);
					f(s, i + 1, res, cur);
					cur.pop_back();
				}
			}
		}
	}

	bool check(string t) {
		int start = 0;
		int end = t.size() - 1;
		while (start < end) {
			if (t[start] == t[end]) {
				start++;
				end--;
			}
			else {
				break;
			}
		}
		return start >= end;
	}
};