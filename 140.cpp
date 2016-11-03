//http://blog.csdn.net/fightforyourdream/article/details/38530983
class Solution {
public:
	vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<string> ans;
		int l = s.size();
		if (l == 0) return ans;
		vector<bool> dp(l, true);
		string res;
		helper(s, wordDict, 0, l, res, ans, dp);
		return ans;
	}

	void helper(string &s, unordered_set<string>& wordDict, int start, int len, string& res, vector<string> & ans, vector<bool>& dp) {
		if (start == len) {
			string tmp = res.substr(1, res.size() - 1);
			ans.push_back(tmp);
			return;
		}
		for (int i = start; i < len; ++i) {
			string t = s.substr(start, i - start + 1);
			if (wordDict.count(t) && dp[i + 1]) {
				res = res + " " + t;
				int c = ans.size();
				helper(s, wordDict, i + 1, len, res, ans, dp);
				if (c == ans.size()) dp[i + 1] = false;
				res.resize(res.size() - t.size() - 1);
			}
		}
	}
};