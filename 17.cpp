class Solution {
private:
	string m[8] = { "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ans;
		string v;
		if (digits.size() == 0) return ans;
		f(digits, 0, v, ans);
		return ans;
	}

	void f(string &digits, int pos, string &v, vector<string> &ans) {
		if (pos == digits.size()) {
			ans.push_back(v);
		}
		else {
			for (auto c : m[digits[pos] - '2']) {
				v += c;
				f(digits, pos + 1, v, ans);
				v = v.substr(0, v.size() - 1);
			}
		}
	}
};