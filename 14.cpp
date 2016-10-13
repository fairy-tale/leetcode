class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string ans = "";
		if (strs.size() == 0) return  ans;
		int n = strs[0].size();
		for (int i = 1; i < strs.size(); ++i) {
			if (strs[i].size() == 0) return ans;
			n = min(n, int(strs[i].size()));
			for (int j = 0; j <= n; ++j) {
				if (strs[0][j] != strs[i][j]) n = j;
			}
		}
		return strs[0].substr(0, n);
	}
};