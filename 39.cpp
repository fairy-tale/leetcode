class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		// unordered_set<int> s;
		// for (auto n : candidates) s.insert(n);
		// vector<int> candidate;
		// for (auto n : s) candidate.push_back(n);
		vector<vector<int>> ans;
		vector<int> cur;
		f(candidates, 0, target, ans, cur);
		return ans;
	}

	void f(vector<int>& candidates, int k, int target, vector<vector<int>>& ans, vector<int>& cur) {
		if (target == 0) {
			ans.push_back(cur);
		}
		else {
			for (int i = k; i < candidates.size(); ++i) {
				if (target - candidates[i] >= 0) {
					cur.push_back(candidates[i]);
					f(candidates, i, target - candidates[i], ans, cur);
					cur.pop_back();
				}
			}
		}
	}
};