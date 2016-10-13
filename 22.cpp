class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		f(n, n, "", ans);
		return ans;
	}

	void f(int front, int back, string v, vector<string> &ans) {
		if (back) {
			if (front) f(front - 1, back, v + '(', ans);
			if (front < back) f(front, back - 1, v + ')', ans);
		}
		else {
			ans.push_back(v);
		}
	}
};