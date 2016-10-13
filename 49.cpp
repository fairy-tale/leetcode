class Solution {
public:
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> res;
		unordered_map<string, int> h;
		int index = 0;
		for (auto &s : strs) {
			string tmp = s;
			sort(tmp.begin(), tmp.end());
			if (!h.count(tmp)) {
				res.push_back({ s });
				h[tmp] = index++;
			}
			else {
				res[h[tmp]].push_back(s);
			}
		}
		return res;
	}
};